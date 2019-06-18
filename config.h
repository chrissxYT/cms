char *reportcommands[] =
{
        "notify-send \"%smsg% Check cms for further information!\"",
};

check checks[] =
{
        {"ping -c 1 1.1.1.1", "Either CloudFlare is offline, your computer is broken or you are offline.", "You're offline.", 2},
        {"[ $(curl ipinfo.io/ip) = $(dig +short chrissx.ga) ]", "For 30 minutes the IP of chrissx.ga isn't yours.", "DynDNS doesn't work.", 6},
        {"[ $(curl ipinfo.io/ip) = $(dig +short zerm.chrissx.ga) ]", "For 30 minutes the IP of zerm.chrissx.ga isn't yours.", "DynDNS doesn't work.", 6},
};

const int interval = 300;
