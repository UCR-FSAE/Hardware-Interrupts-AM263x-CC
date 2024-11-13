################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16 -mlittle-endian -mthumb -Os -I"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/include/c" -I"C:/ti/mcu_plus_sdk_am263x_10_00_00_35/source" -DSOC_AM263X -g -Wall -Wno-gnu-variable-sized-type-not-at-end -Wno-unused-function -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"C:/Users/steve/workspace_v12/InterruptTest/Release/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1516075823: ../example.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs1281/ccs/utils/sysconfig_1.21.0/sysconfig_cli.bat" --script "C:/Users/steve/workspace_v12/InterruptTest/example.syscfg" -o "syscfg" -s "C:/ti/mcu_plus_sdk_am263x_10_00_00_35/.metadata/product.json" --context "r5fss0-0" --part AM263x --package ZCZ --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_dpl_config.c: build-1516075823 ../example.syscfg
syscfg/ti_dpl_config.h: build-1516075823
syscfg/ti_drivers_config.c: build-1516075823
syscfg/ti_drivers_config.h: build-1516075823
syscfg/ti_drivers_open_close.c: build-1516075823
syscfg/ti_drivers_open_close.h: build-1516075823
syscfg/ti_pinmux_config.c: build-1516075823
syscfg/ti_power_clock_config.c: build-1516075823
syscfg/ti_board_config.c: build-1516075823
syscfg/ti_board_config.h: build-1516075823
syscfg/ti_board_open_close.c: build-1516075823
syscfg/ti_board_open_close.h: build-1516075823
syscfg/ti_enet_config.c: build-1516075823
syscfg/ti_enet_config.h: build-1516075823
syscfg/ti_enet_open_close.c: build-1516075823
syscfg/ti_enet_open_close.h: build-1516075823
syscfg/ti_enet_soc.c: build-1516075823
syscfg/ti_enet_lwipif.c: build-1516075823
syscfg/ti_enet_lwipif.h: build-1516075823
syscfg/linker.cmd: build-1516075823
syscfg/linker_defines.h: build-1516075823
syscfg: build-1516075823

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-r5 -mfloat-abi=hard -mfpu=vfpv3-d16 -mlittle-endian -mthumb -Os -I"C:/ti/ccs1281/ccs/tools/compiler/ti-cgt-armllvm_4.0.0.LTS/include/c" -I"C:/ti/mcu_plus_sdk_am263x_10_00_00_35/source" -DSOC_AM263X -g -Wall -Wno-gnu-variable-sized-type-not-at-end -Wno-unused-function -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"C:/Users/steve/workspace_v12/InterruptTest/Release/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


