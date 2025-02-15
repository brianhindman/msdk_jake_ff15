/******************************************************************************
 * Copyright (C) 2022 Maxim Integrated Products, Inc., All rights Reserved.
 * 
 * This software is protected by copyright laws of the United States and
 * of foreign countries. This material may also be protected by patent laws
 * and technology transfer regulations of the United States and of foreign
 * countries. This software is furnished under a license agreement and/or a
 * nondisclosure agreement and may only be used or reproduced in accordance
 * with the terms of those agreements. Dissemination of this information to
 * any party or parties not specified in the license agreement and/or
 * nondisclosure agreement is expressly prohibited.
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 ******************************************************************************/

#ifndef LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32570_INCLUDE_SYSTEM_MAX32570_H_
#define LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32570_INCLUDE_SYSTEM_MAX32570_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/

/* NOTE: HIRC was previously named CRYPTO */
#ifdef CRYPTO_FREQ
#warning WARNING: CRYPTO_FREQ does not exist in MAX32570, replace with ISO_FREQ!
#define ISO_FREQ CRYPTO_FREQ
#endif

/* NOTE: ISO was previously HIRC. */
#ifndef ISO_FREQ
#define ISO_FREQ 75000000
#endif

/* NOTE: This is the nominal value for INRO. The actual value may vary from chip to chip. 
         Update if use of this oscillator requires precise timing.*/
/* NOTE: INO was previosly LIRC8  */
#ifndef INRO_FREQ
#define INRO_FREQ 8000
#endif

/* NOTE: IPO was previously HIRC96. */
#ifndef IPO_FREQ
#define IPO_FREQ 150000000
#endif

/* NOTE: IBRO was previously HIRC8M. */
#ifndef IBRO_FREQ
#define IBRO_FREQ 7372800
#endif

/* NOTE: ERFO was previously XTAL27M. */
#ifndef ERFO_FREQ
#define ERFO_FREQ 27120000
#endif

/* NOTE: ERTCO was previously XTAL32K. */
#ifndef ERTCO_FREQ
#define ERTCO_FREQ 32768
#endif

extern uint32_t SystemCoreClock; /*!< System Clock Frequency (Core Clock)  */
#ifdef PeripheralClock
#warning PeripheralClock define is being overidden.
#else
#define PeripheralClock (SystemCoreClock / 2) /*!< Peripheral Clock Frequency */
#endif

/*
 * Initialize the system
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
void SystemInit(void);

/*
 * Update SystemCoreClock variable
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif // LIBRARIES_CMSIS_DEVICE_MAXIM_MAX32570_INCLUDE_SYSTEM_MAX32570_H_
