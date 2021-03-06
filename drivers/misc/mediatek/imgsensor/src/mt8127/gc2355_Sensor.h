/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *	 sensor.c
 *
 * Project:
 * --------
 *	 RAW
 *
 * Description:
 * ------------
 *	 Source code of Sensor driver
 *
 *
 * Author:
 * -------
 *   Leo Lee
 *
 *============================================================================
 *             HISTORY
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 03 01 2013
 * First release GC2355 driver Version 1.0
 *
 *------------------------------------------------------------------------------
 *============================================================================
 ****************************************************************************/

#ifndef _GC2355_SENSOR_H
#define _GC2355_SENSOR_H

#define GC2355_DEBUG
#define GC2355_DRIVER_TRACE
//#define GC2355_TEST_PATTEM

#define GC2355_FACTORY_START_ADDR 0
#define GC2355_ENGINEER_START_ADDR 10
 
typedef enum GC2355_group_enum
{
  GC2355_PRE_GAIN = 0,
  GC2355_CMMCLK_CURRENT,
  GC2355_FRAME_RATE_LIMITATION,
  GC2355_REGISTER_EDITOR,
  GC2355_GROUP_TOTAL_NUMS
} GC2355_FACTORY_GROUP_ENUM;

typedef enum GC2355_register_index
{
  GC2355_SENSOR_BASEGAIN = GC2355_FACTORY_START_ADDR,
  GC2355_PRE_GAIN_R_INDEX,
  GC2355_PRE_GAIN_Gr_INDEX,
  GC2355_PRE_GAIN_Gb_INDEX,
  GC2355_PRE_GAIN_B_INDEX,
  GC2355_FACTORY_END_ADDR
} GC2355_FACTORY_REGISTER_INDEX;

typedef enum GC2355_engineer_index
{
  GC2355_CMMCLK_CURRENT_INDEX = GC2355_ENGINEER_START_ADDR,
  GC2355_ENGINEER_END
} GC2355_FACTORY_ENGINEER_INDEX;

typedef struct _sensor_data_struct
{
  SENSOR_REG_STRUCT reg[GC2355_ENGINEER_END];
  SENSOR_REG_STRUCT cct[GC2355_FACTORY_END_ADDR];
} sensor_data_struct;

/* SENSOR PREVIEW/CAPTURE VT CLOCK */
#define GC2355_PREVIEW_CLK                   42000000
#define GC2355_CAPTURE_CLK                   42000000

#define GC2355_COLOR_FORMAT                    SENSOR_OUTPUT_FORMAT_RAW_B //SENSOR_OUTPUT_FORMAT_RAW_Gb //SENSOR_OUTPUT_FORMAT_RAW_R

#define GC2355_MIN_ANALOG_GAIN				1	/* 1x */
#define GC2355_MAX_ANALOG_GAIN				4	/* 2.8x */


/* FRAME RATE UNIT */
#define GC2355_FPS(x)                          (10 * (x))

/* SENSOR PIXEL/LINE NUMBERS IN ONE PERIOD */

#define GC2355_FULL_PERIOD_PIXEL_NUMS          1126
#define GC2355_FULL_PERIOD_LINE_NUMS           1242

#define GC2355_VIDEO_PERIOD_PIXEL_NUMS          1126
#define GC2355_VIDEO_PERIOD_LINE_NUMS           1242

#define GC2355_PV_PERIOD_PIXEL_NUMS            1126
#define GC2355_PV_PERIOD_LINE_NUMS             1242

/* SENSOR START/END POSITION */
#define GC2355_FULL_X_START                    0   
#define GC2355_FULL_Y_START                    0  
#define GC2355_IMAGE_SENSOR_FULL_WIDTH         (1600 - 8) 
#define GC2355_IMAGE_SENSOR_FULL_HEIGHT        (1200 - 6) 

#define GC2355_VIDEO_X_START                      0
#define GC2355_VIDEO_Y_START                      0
#define GC2355_IMAGE_SENSOR_VIDEO_WIDTH           (1600) 
#define GC2355_IMAGE_SENSOR_VIDEO_HEIGHT          (1200) 

#define GC2355_PV_X_START                      0
#define GC2355_PV_Y_START                      0
#define GC2355_IMAGE_SENSOR_PV_WIDTH           (1600 - 8) 
#define GC2355_IMAGE_SENSOR_PV_HEIGHT          (1200 - 6)

/* SENSOR READ/WRITE ID */
#define GC2355_WRITE_ID (0x78)
#define GC2355_READ_ID  (0x79)

/* SENSOR ID */
//#define GC2355_SENSOR_ID						(0x2355)

/* SENSOR PRIVATE STRUCT */
typedef enum {
    SENSOR_MODE_INIT = 0,
    SENSOR_MODE_PREVIEW,
    SENSOR_MODE_VIDEO,
    SENSOR_MODE_CAPTURE
} GC2355_SENSOR_MODE;

typedef enum{
	GC2355_IMAGE_NORMAL = 0,
	GC2355_IMAGE_H_MIRROR,
	GC2355_IMAGE_V_MIRROR,
	GC2355_IMAGE_HV_MIRROR
}GC2355_IMAGE_MIRROR;

typedef struct GC2355_sensor_STRUCT
{
	MSDK_SENSOR_CONFIG_STRUCT cfg_data;
	sensor_data_struct eng; /* engineer mode */
	MSDK_SENSOR_ENG_INFO_STRUCT eng_info;
	GC2355_SENSOR_MODE sensorMode;
	GC2355_IMAGE_MIRROR Mirror;
	kal_bool pv_mode;
	kal_bool video_mode;
	kal_bool NightMode;
	kal_uint16 normal_fps; /* video normal mode max fps */
	kal_uint16 night_fps; /* video night mode max fps */
	kal_uint16 FixedFps;
	kal_uint16 shutter;
	kal_uint16 gain;
	kal_uint32 pclk;
	kal_uint16 frame_height;
	kal_uint16 frame_height_BackUp;
	kal_uint16 line_length;  
	kal_uint16 Prv_line_length;
} GC2355_sensor_struct;

typedef enum GC2355_GainMode_Index
{
	GC2355_Analogic_Gain = 0,
	GC2355_Digital_Gain
}GC2355_GainMode_Index;
//export functions
UINT32 GC2355Open(void);
UINT32 GC2355Control(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 GC2355FeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId, UINT8 *pFeaturePara,UINT32 *pFeatureParaLen);
UINT32 GC2355GetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_INFO_STRUCT *pSensorInfo, MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData);
UINT32 GC2355GetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution);
UINT32 GC2355Close(void);

#define Sleep(ms) mdelay(ms)

#endif 
