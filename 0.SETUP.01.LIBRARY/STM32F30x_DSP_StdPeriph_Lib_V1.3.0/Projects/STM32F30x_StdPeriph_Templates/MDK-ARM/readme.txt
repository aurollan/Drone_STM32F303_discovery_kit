/**
  @page mdkarm MDK-ARM Project Template for STM32F30xx devices
  
  @verbatim
  ******************* (C) COPYRIGHT 2015 STMicroelectronics ********************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.2.3
  * @date    15-December-2021
  * @brief   This sub-directory contains all the user-modifiable files 
  *          needed to create a new project linked with the STM32F30x  
  *          Standard Peripheral Library and working with RealView Microcontroller
  *          Development Kit(MDK-ARM) software toolchain
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  @endverbatim
 
 @par Directory contents
 
 - Project.uvprojx/.uvoptx: A pre-configured project file with the provided library structure
                          that produces an executable image with MDK-ARM.

Enabling "Options for Target — Output – Browser Information" is useful for quick 
source files navigation but may slow the compilation time.
 
 
 @par How to use it ?
 
 - Open the Project.uvproj project
 - In the build toolbar select the project config:
      - STM32F303xC: to configure the project for STM32F303xC devices.
                     You can use STMicroelectronics STM32303C-EVAL board to run this project.
                     
      - STM32F303xE: to configure the project for STM32F303xE devices.
                     You need to use custom HW board to run this project. 
                     
      - STM32F302x8: to configure the project for STM32F302x8 devices.
                     You can use STMicroelectronics Nucleo to run this project.
                     
      - STM32F334x8: to configure the project for STM32F334x8 devices.
                     You can use STMicroelectronics Discovery to run this project.
                     
 - Rebuild all files: Project->Rebuild all target files
 - Load project image: Debug->Start/Stop Debug Session
 - Run program: Debug->Run (F5) 


 */