
#ifndef __CICLO_H__
#define	__CICLO_H__

typedef enum {
            BASE = 0,
            TRIGGER,
} MODE;

#define S_1_2       0
#define S_3_4       1

void gt_ciclo(MODE mode);
MODE readConfiguration();

#endif