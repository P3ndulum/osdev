// ------------------------------------------------------------------------------------------------
// console/cmd.c
// ------------------------------------------------------------------------------------------------

#include "console/cmd.h"
#include "console/console.h"
#include "cpu/io.h"
#include "gfx/gfx.h"
#include "net/dns.h"
#include "net/icmp.h"
#include "net/ipv4.h"
#include "net/net.h"
#include "net/port.h"
#include "net/ntp.h"
#include "net/udp.h"
#include "stdlib/string.h"
#include "time/pit.h"
#include "time/rtc.h"

// ------------------------------------------------------------------------------------------------
static void cmd_datetime(uint argc, const char** argv)
{
    char buf[TIME_STRING_SIZE];

    DateTime dt;
    rtc_get_time(&dt);
    format_time(buf, sizeof(buf), &dt);

    console_print("%s\n", buf);
}

// ------------------------------------------------------------------------------------------------
static void cmd_echo(uint argc, const char** argv)
{
    for (uint i = 0; i < argc; ++i)
    {
        console_print("%s\n", argv[i]);
    }
}

// ------------------------------------------------------------------------------------------------
static void cmd_hello(uint argc, const char** argv)
{
    console_print("Hello World.\n");
}

// ------------------------------------------------------------------------------------------------
static void cmd_help(uint argc, const char** argv)
{
    ConsoleCmd* cmd = console_cmd_table;
    while (cmd->name)
    {
        console_print("%s\n", cmd->name);

        ++cmd;
    }
}

// ------------------------------------------------------------------------------------------------
static void cmd_host(uint argc, const char** argv)
{
    if (argc != 2)
    {
        console_print("Usage: host <host name>\n");
        return;
    }

    const char* host_name = argv[1];

    dns_query_host(host_name, 0);
}

// ------------------------------------------------------------------------------------------------
static void cmd_lsroute(uint argc, const char** argv)
{
    ipv4_print_route_table();
}

// ------------------------------------------------------------------------------------------------
static void cmd_ping(uint argc, const char** argv)
{
    if (argc != 2)
    {
        console_print("Usage: ping <dest ipv4 address>\n");
        return;
    }

    IPv4_Addr dst_addr;
    if (!str_to_ipv4_addr(&dst_addr, argv[1]))
    {
        console_print("Failed to parse destination address\n");
        return;
    }

    icmp_echo_request(&dst_addr, 1, 2, 0, 0);
}

// ------------------------------------------------------------------------------------------------
static void cmd_synctime(uint argc, const char** argv)
{
    if (argc != 2)
    {
        console_print("Usage: synctime <dest ipv4 address>\n");
        return;
    }

    IPv4_Addr dst_addr;
    if (!str_to_ipv4_addr(&dst_addr, argv[1]))
    {
        console_print("Failed to parse destination address\n");
        return;
    }

    ntp_tx(&dst_addr);
}

// ------------------------------------------------------------------------------------------------
static void cmd_reboot(uint argc, const char** argv)
{
    out8(0x64, 0xfe);   // Send reboot command to keyboard controller
}

// ------------------------------------------------------------------------------------------------
static void cmd_rlog(uint argc, const char** argv)
{
    if (argc != 2)
    {
        console_print("Usage: rlog <message>\n");
        return;
    }

    const char* msg = argv[1];
    uint len = strlen(msg) + 1;
    if (len > 1024)
    {
        console_print("Message too long\n");
        return;
    }

    // For each interface, broadcast a packet
    Link* it = g_net_intf_list.next;
    Link* end = &g_net_intf_list;

    while (it != end)
    {
        Net_Intf* intf = link_data(it, Net_Intf, link);

        if (!ipv4_addr_eq(&intf->broadcast_addr, &null_ipv4_addr))
        {
            NetBuf* buf = net_alloc_packet();
            u8* pkt = (u8*)(buf + 1);

            strcpy((char*)pkt, msg);

            udp_tx(&intf->broadcast_addr, PORT_OSHELPER, PORT_OSHELPER, pkt, len);
        }

        it = it->next;
    }
}

// ------------------------------------------------------------------------------------------------
static void cmd_ticks(uint argc, const char** argv)
{
    console_print("%d\n", pit_ticks);
}

// ------------------------------------------------------------------------------------------------
static void cmd_gfx(uint argc, const char** argv)
{
    console_print("Starting 3D graphics...\n");
	gfx_start();
}


// ------------------------------------------------------------------------------------------------
ConsoleCmd console_cmd_table[] =
{
    { "datetime", cmd_datetime },
    { "echo", cmd_echo },
    { "hello", cmd_hello },
    { "help", cmd_help },
    { "host", cmd_host },
    { "lsroute", cmd_lsroute },
    { "ping", cmd_ping },
    { "reboot", cmd_reboot },
    { "rlog", cmd_rlog },
    { "synctime", cmd_synctime },
    { "ticks", cmd_ticks },
	{ "gfx", cmd_gfx },
    { 0, 0 },
};