#include "zf_common_headfile.h"
#include "duoji.h"
#include "motor.h"

int main(void)
{
    clock_init(SYSTEM_CLOCK_120M); // 初始化芯片时钟 工作频率为 120MHz
    debug_init();                  // 务必保留，本函数用于初始化MPU 时钟 调试串口

    duoji_init(90);

    motor_init();

    left_motor_set_speed(18);
    right_motor_set_speed(18);

    tft180_init();
    tft180_set_color(RGB565_WHITE,RGB565_BLACK);
    tft180_set_font(TFT180_6X8_FONT);
    tft180_clear();

    while (1)
    {

        motor_run_it();

        tft180_show_int(0, 0, left_motor_speed_now, 4);
        tft180_show_int(0, 8, right_motor_speed_now, 4);

        system_delay_ms(10);
//        motor_set_dir(MOTOR_BACKWARD);
//
//        system_delay_ms(2000);
//
//        motor_set_dir(MOTOR_FORWARD);
//
//        system_delay_ms(2000);
    }
}
