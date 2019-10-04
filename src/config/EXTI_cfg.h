/*
 * EXTI_cfg.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_EXTI_CFG_H_
#define F15_REPO_SRC_CONFIG_EXTI_CFG_H_

/*
 * Choose between the followings
 * EXTI_EDGE_RISING_msk
 * EXTI_EDGE_FALLING_msk
 * EXTI_EDGE_BOTH_msk
 * EXTI_EDGE_LOW_LEVEL_msk
 *
 * */
#define EXTI_EDGE_SELECTOR_INT0_msk				EXTI_EDGE_RISING_msk
#define EXTI_EDGE_SELECTOR_INT1_msk				EXTI_EDGE_FALLING_msk
#define EXTI_EDGE_SELECTOR_INT2_msk				EXTI_EDGE_RISING_msk

#define EXTI_ENABLE_INT0						ENABLE
#define EXTI_ENABLE_INT1						DISABLE
#define EXTI_ENABLE_INT2						DISABLE

#endif /* F15_REPO_SRC_CONFIG_EXTI_CFG_H_ */
