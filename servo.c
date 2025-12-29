#include "servo.h"

void  servo_init(servo_t *s){
	HAL_TIM_PWM_Start(s->htim, s->channel);
}

// this function is for positional rotation servos
void servo_set_angle(servo_t *s,float angle,dir_servo_t direction){// you select the angle from 0 to 90 and select the direction
	uint16_t duty_cycle;
	 if (angle > 90) angle = 90;
	 if (angle < 0) angle = 0;
	if(direction == POS_ROT){
	duty_cycle = 750 + (250 * angle)/90 ;
	}else duty_cycle = 750 - (250 * angle)/90;

	 __HAL_TIM_SET_COMPARE(s->htim, s->channel, duty_cycle);
}
// this function for the servo smoothly
void servo_move_smooth(servo_t *s, float angle, float speed, dir_servo_t direction) {

    if (s->current_angle < angle) {
        s->current_angle += speed;
        if (s->current_angle > angle) s->current_angle = angle;
    } else if (s->current_angle > angle) {
        s->current_angle -= speed;
        if (s->current_angle < angle) s->current_angle = angle;
    }


    servo_set_angle(s, s->current_angle, direction);
}


// this functions are for continuous rotation servos
void servo_set_speed(servo_t *s,uint16_t speed,dir_servo_t direction){// you select speed from 0 to 90 and select the direction
	uint16_t pwm_speed;
		if(direction == POS_ROT){
		pwm_speed = 750 + (250 * speed)/90;
		}else pwm_speed = 750 - (250 * speed)/90;

		 __HAL_TIM_SET_COMPARE(s->htim, s->channel, pwm_speed);
}
// function to stop the servo or put in 0 position

void  servo_stop(servo_t *s){
	 __HAL_TIM_SET_COMPARE(s->htim, s->channel, 750);

}
