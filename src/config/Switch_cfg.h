/*
 * SWITCH_cfg.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_SWITCH_CFG_H_
#define F15_REPO_SRC_CONFIG_SWITCH_CFG_H_

/* each count represent 10ms*/
#define SWITCH_MAX_DEBOUNCE_COUNTER				5
typedef enum
{
	SW_Name_0,
	SW_Name_1,
	SW_Name_2,
	SW_Name_3,
	SW_Name_4,
	SW_Name_5,
	SW_Name_6,
	SW_Name_7,
	/*
	 * add switches Names to be configured
	 * */

	MaxNumOfSwitches
}SW_NameType;

#endif /* F15_REPO_SRC_CONFIG_SWITCH_CFG_H_ */
