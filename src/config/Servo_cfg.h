/*
 * Servo_cfg.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_EHAL_SERVO_SERVO_CFG_H_
#define E15_REPO_SRC_EHAL_SERVO_SERVO_CFG_H_

/**========================================================
 * CONFIGURATION
 **========================================================*/

#define SERVO_SIGNAL_PIN									Dio_Channel_D7

#define SERVO_PWM_SIGNAL_DUARTION_STEPS_DIV_BY_FACTOR		250		/* 2 ms */
#define SERVO_PWM_SIGNAL_FACTOR								10		/* 2*10 = 20 ms */

#define SERVO_MAX_ANGLE_STEPS								250		/* 2 ms  */
#define SERVO_MIN_ANGLE_STEPS								125		/* 1 ms  */
#define SERVO_MAX_ANGLE_DEGREE								180
#define SERVO_MIN_ANGLE_DEGREE								0


#endif /* E15_REPO_SRC_EHAL_SERVO_SERVO_CFG_H_ */
