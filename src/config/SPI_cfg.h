/*
 * SPI_cfg.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_SPI_CFG_H_
#define F15_REPO_SRC_CONFIG_SPI_CFG_H_



/*
 * Configure Data order with the followings
 * SPI_DATA_ORDER_LSB_msk
 * SPI_DATA_ORDER_MSB_msk
 * */
#define SPI_DATA_ORDER_SELECTOR			SPI_DATA_ORDER_MSB_msk


/*
 * Configure SPI_OPERATION_MODE with the followings
 * SPI_OPERATION_MODE_MASTER_msk
 * SPI_OPERATION_MODE_SLAVE_msk
 * */
#define SPI_OPERATION_MODE_SELECTOR		SPI_OPERATION_MODE_MASTER_msk

/*
 * configure sck level in idle status
 * SPI_SCK_IDLE_LEVEL_HIGH
 * SPI_SCK_IDLE_LEVEL_LOW
 * */
#define SPI_SCK_IDLE_LEVEL_SELECTOR		SPI_SCK_IDLE_LEVEL_HIGH

/*
 * configure operation on leading edge
 * SPI_LEADING_EDGE_OPR_SAMPLE
 * SPI_LEADING_EDGE_OPR_SETUP
 * */
#define SPI_LEADING_EDGE_OPR_SELCTOR	SPI_LEADING_EDGE_OPR_SAMPLE

/*
 * configure spi prescaler
 * SPI_PRESCALER_4
 * SPI_PRESCALER_16
 * SPI_PRESCALER_64
 * SPI_PRESCALER_128
 * */
#define SPI_PRESCALER_SELECTOR			SPI_PRESCALER_128

#define SPI_DOUBLE_SPEED				ENABLE

#define SPI_RX_BUFFER_SIZE				50
#endif /* F15_REPO_SRC_CONFIG_SPI_CFG_H_ */
