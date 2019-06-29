char *reportcommands[] =
{
        "notify-send \"%smsg%\nCheck cms for further information!\"",
};

check checks[] =
{
        {"ping -c 1 1.1.1.1", "Either CloudFlare is offline, your computer is broken or you are offline.", "You're offline.", 2},
        {"[ \"$(curl ipinfo.io/ip)\" = \"$(dig +short chrissx.ga)\" ]", "For 30 minutes the IP of chrissx.ga isn't yours.", "DynDNS doesn't work.", 6},
        {"[ \"$(curl ipinfo.io/ip)\" = \"$(dig +short zerm.chrissx.ga)\" ]", "For 30 minutes the IP of zerm.chrissx.ga isn't yours.", "DynDNS doesn't work.", 6},
        {"curl chrissx.ga", "Can't cURL chrissx.ga, it is probably offline.", "chrissx.ga is offline!", 3},
};

const int interval = 300;
