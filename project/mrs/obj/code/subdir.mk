################################################################################
# MRS Version: 1.9.2
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/duoji.c \
H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/fast_compute.c \
H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/motor.c \
H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/pid.c 

OBJS += \
./code/duoji.o \
./code/fast_compute.o \
./code/motor.o \
./code/pid.o 

C_DEPS += \
./code/duoji.d \
./code/fast_compute.d \
./code/motor.d \
./code/pid.d 


# Each subdirectory must supply rules for building sources it contributes
code/duoji.o: H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/duoji.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_components" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/fast_compute.o: H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/fast_compute.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_components" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/motor.o: H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/motor.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_components" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/pid.o: H:/MounRiverProj/Seekfree_CH32V307VCT6_Opensource_Library/project/code/pid.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_components" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"H:\MounRiverProj\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

