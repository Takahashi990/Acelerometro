################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/grace/InterruptVectors_init.obj: ../src/grace/InterruptVectors_init.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti3/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=eabi --include_path="C:/ti3/ccsv5/ccs_base/msp430/include" --include_path="C:/ti3/ccsv5/tools/compiler/msp430_4.2.1/include" --include_path="C:/ti3/ccsv5/ccs_base/msp430/msp430ware_1_40_01_44" --advice:power=all -g --define=__MSP430F2274__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="src/grace/InterruptVectors_init.pp" --obj_directory="src/grace" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


