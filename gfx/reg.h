// ------------------------------------------------------------------------------------------------
// gfx/reg.h
// ------------------------------------------------------------------------------------------------

#include "stdlib/types.h"

// ------------------------------------------------------------------------------------------------
// Vol 3. Part 1. VGA and Extended VGA Registers
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 1.2.1 Sequencer Index

#define SR_INDEX                        0x3c4
#define SR_DATA                         0x3c5

// ------------------------------------------------------------------------------------------------
// 1.2.3 Clocking Mode

#define SEQ_CLOCKING                    0x01
#define SCREEN_OFF                      (1 << 5)

// ------------------------------------------------------------------------------------------------
// Vol 3. Part 3. North Display Engine Registers
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 3.1.1 VGA Control

#define VGA_CONTROL                     0x41000     // R/W

#define VGA_DISABLE                     (1 << 31)

// ------------------------------------------------------------------------------------------------
// 4.1.1 Horizontal Total

#define PIPE_HTOTAL_A                   0x60000     // R/W
#define PIPE_HTOTAL_B                   0x61000     // R/W
#define PIPE_HTOTAL_C                   0x62000     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.2 Horizontal Blank

#define PIPE_HBLANK_A                   0x60004     // R/W
#define PIPE_HBLANK_B                   0x61004     // R/W
#define PIPE_HBLANK_C                   0x62004     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.3 Horizontal Sync

#define PIPE_HSYNC_A                    0x60008     // R/W
#define PIPE_HSYNC_B                    0x61008     // R/W
#define PIPE_HSYNC_C                    0x62008     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.4 Vertical Total

#define PIPE_VTOTAL_A                   0x6000c     // R/W
#define PIPE_VTOTAL_B                   0x6100c     // R/W
#define PIPE_VTOTAL_C                   0x6200c     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.5 Vertical Blank

#define PIPE_VBLANK_A                   0x60010     // R/W
#define PIPE_VBLANK_B                   0x61010     // R/W
#define PIPE_VBLANK_C                   0x62010     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.6 Vertical Sync

#define PIPE_VSYNC_A                    0x60014     // R/W
#define PIPE_VSYNC_B                    0x61014     // R/W
#define PIPE_VSYNC_C                    0x62014     // R/W

// ------------------------------------------------------------------------------------------------
// 4.1.7 Source Image Size

#define PIPE_SRCSZ_A                    0x6001c     // R/W
#define PIPE_SRCSZ_B                    0x6101c     // R/W
#define PIPE_SRCSZ_C                    0x6201c     // R/W

// ------------------------------------------------------------------------------------------------
// 5.1.3 Pipe Configuration

#define PIPE_CONF_A                     0x70008     // R/W
#define PIPE_CONF_B                     0x71008     // R/W
#define PIPE_CONF_C                     0x72008     // R/W

// ------------------------------------------------------------------------------------------------
// 5.2.1 Cursor Control

#define CUR_CTL_A                       0x70080     // R/W
#define CUR_CTL_B                       0x71080     // R/W
#define CUR_CTL_C                       0x72080     // R/W

#define CUR_GAMMA_ENABLE                (1 << 26)   // Gamma Enable
#define CUR_MODE_ARGB                   (1 << 5)    // 32bpp ARGB
#define CUR_MODE_64_32BPP               (7 << 0)    // 64 x 64 32bpp

// ------------------------------------------------------------------------------------------------
// 5.2.2 Cursor Base

#define CUR_BASE_A                      0x70084     // R/W
#define CUR_BASE_B                      0x71084     // R/W
#define CUR_BASE_C                      0x72084     // R/W

// ------------------------------------------------------------------------------------------------
// 5.2.3 Cursor Position

#define CUR_POS_A                       0x70088     // R/W
#define CUR_POS_B                       0x71088     // R/W
#define CUR_POS_C                       0x72088     // R/W

// ------------------------------------------------------------------------------------------------
// 5.3.1 Primary Control

#define PRI_CTL_A                       0x70180     // R/W
#define PRI_CTL_B                       0x71180     // R/W
#define PRI_CTL_C                       0x72180     // R/W

#define PRI_PLANE_ENABLE                (1 << 31)
#define PRI_PLANE_32BPP                 (6 << 26)

// ------------------------------------------------------------------------------------------------
// 5.3.2 Primary Linear Offset

#define PRI_LINOFF_A                    0x70184     // R/W
#define PRI_LINOFF_B                    0x71184     // R/W
#define PRI_LINOFF_C                    0x72184     // R/W

// ------------------------------------------------------------------------------------------------
// 5.3.3 Primary Stride

#define PRI_STRIDE_A                    0x70188     // R/W
#define PRI_STRIDE_B                    0x71188     // R/W
#define PRI_STRIDE_C                    0x72188     // R/W

// ------------------------------------------------------------------------------------------------
// 5.3.4 Primary Surface Base Address

#define PRI_SURF_A                      0x7019c     // R/W
#define PRI_SURF_B                      0x7119c     // R/W
#define PRI_SURF_C                      0x7219c     // R/W

// ------------------------------------------------------------------------------------------------
// 5.3.5 Primary Tiled Offset

#define PRI_TILEOFF_A                   0x701a4     // R/W
#define PRI_TILEOFF_B                   0x711a4     // R/W
#define PRI_TILEOFF_C                   0x721a4     // R/W

// ------------------------------------------------------------------------------------------------
// Vol 3. Part 4. South Display Engine Registers
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// 3.6.1 HDMI Port Control

#define HDMI_CTL_B                      0xe1140     // R/W
#define HDMI_CTL_C                      0xe1150     // R/W
#define HDMI_CTL_D                      0xe1160     // R/W

#define PORT_DETECTED                   (1 << 2)    // RO