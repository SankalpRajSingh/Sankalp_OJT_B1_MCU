################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/gpio_funcn.c \
../driver/Src/stm32f411x_driver_gpio.c 

OBJS += \
./driver/Src/gpio_funcn.o \
./driver/Src/stm32f411x_driver_gpio.o 

C_DEPS += \
./driver/Src/gpio_funcn.d \
./driver/Src/stm32f411x_driver_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/%.o driver/Src/%.su: ../driver/Src/%.c driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"C:/Users/PHY202209EF07/STM32CubeIDE/workspace_1.10.1/02_EMPTY_PROJECT/driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-driver-2f-Src

clean-driver-2f-Src:
	-$(RM) ./driver/Src/gpio_funcn.d ./driver/Src/gpio_funcn.o ./driver/Src/gpio_funcn.su ./driver/Src/stm32f411x_driver_gpio.d ./driver/Src/stm32f411x_driver_gpio.o ./driver/Src/stm32f411x_driver_gpio.su

.PHONY: clean-driver-2f-Src

