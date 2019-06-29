#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define arrsz(a) (sizeof (a) / sizeof *(a))

#ifndef bool
typedef int bool;
#endif

typedef struct
{
        char *cmd;
        char *msg;
        char *smsg;
        int   fails2notify;
        int   failedcount;
} check;

#include "config.h"

void strrep_msg(char *in, bool smsg, char *new, char *out, char *end)
{
        while(*in)
        {
                char *c = in;
                if(*in++ == '%' && (!smsg || *in++ == 's') &&
                   *in++ == 'm' &&
                   *in++ == 's' &&
                   *in++ == 'g' &&
                   *in++ == '%')
                {
                        c = new;
                        while(*c) *out++ = *c++;
                }
                else *out++ = *c, in = ++c;
        }
        while(out < end) *out++ = '\0';
}

void report(char *msg, char *smsg)
{
        for(int i = 0; i < arrsz(reportcommands); i++)
        {
                size_t len = strlen(reportcommands[i])
                       + strlen(msg) + strlen(smsg) + 64;
                char bfr[len];
                strrep_msg(reportcommands[i], 0, msg, bfr, bfr + len);
                strrep_msg(reportcommands[i], 1, smsg, bfr, bfr + len);
                system(bfr);
        }
}

void checkall()
{
        for(int i = 0; i < arrsz(checks); i++)
        {
                if(system(checks[i].cmd)) checks[i].failedcount++;
                else                      checks[i].failedcount = 0;
                if(checks[i].failedcount >= checks[i].fails2notify)
                        report(checks[i].msg, checks[i].smsg),
                                checks[i].failedcount = 0;
        }
}

int main(int argc, char **argv)
{
        while(1)
        {
                checkall();
                sleep(interval);
        }
}
