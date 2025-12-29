#include "main.h"




typedef struct {
	TIM_HandleTypeDef *htim;
	uint16_t channel;
	float current_angle;

} servo_t;


typedef enum {
	POS_ROT = 0,
	NEG_ROT = 1
} dir_servo_t;

void servo_init(servo_t *s);
void servo_set_angle(servo_t *s,float angle,dir_servo_t direction);
void servo_move_smooth(servo_t *s,float angle ,float speed,dir_servo_t direction);
void servo_set_speed(servo_t *s,uint16_t speed,dir_servo_t direction);
void servo_stop(servo_t *s);

