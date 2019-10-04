/*
 * KP_cfg.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_KP_CFG_H_
#define F15_REPO_SRC_CONFIG_KP_CFG_H_

#define KP_PIN_ROW_0							Dio_Channel_B7
#define KP_PIN_ROW_1							Dio_Channel_B6
#define KP_PIN_ROW_2							Dio_Channel_B5
#define KP_PIN_ROW_3							Dio_Channel_B4


#define KP_PIN_COL_0							Dio_Channel_A3
#define KP_PIN_COL_1							Dio_Channel_A2
#define KP_PIN_COL_2							Dio_Channel_C1
#define KP_PIN_COL_3							Dio_Channel_C0

/*
 * Please Configure values for the following layout
 * 		___________________________________________________________
 *		|KP_BUTON_0	 |	KP_BUTON_1	|	KP_BUTON_2	|	KP_BUTON_3 |
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_4	 |	KP_BUTON_5	|	KP_BUTON_6	|	KP_BUTON_7 |
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_8	 |	KP_BUTON_9	|	KP_BUTON_10	|	KP_BUTON_11|
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_12 |	KP_BUTON_13	|	KP_BUTON_14	|	KP_BUTON_15|
 * 		|____________|______________|_______________|______________|
 */
#define KP_BUTON_0								'1'
#define KP_BUTON_1								'2'
#define KP_BUTON_2								'3'
#define KP_BUTON_3								'+'

#define KP_BUTON_4								'4'
#define KP_BUTON_5								'5'
#define KP_BUTON_6								'6'
#define KP_BUTON_7								'-'

#define KP_BUTON_8								'7'
#define KP_BUTON_9								'8'
#define KP_BUTON_10								'9'
#define KP_BUTON_11								'*'

#define KP_BUTON_12								'='
#define KP_BUTON_13								'0'
#define KP_BUTON_14								'^'
#define KP_BUTON_15								'/'

#define KP_RELEASED								255



#define KP_ACTIVE_TYPE							STD_low
#define KP_INTERNAL_PULL_UP_RESISTOR_EN			ENABLE

#endif /* F15_REPO_SRC_CONFIG_KP_CFG_H_ */
