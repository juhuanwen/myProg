#ifndef __V4L2_H
#define __V4L2_H

#define LOG printf("[%s|%4d|]",__FILE__,__LINE__);printf

extern int Get_Camera_dev_name(char *name, int len);
extern int camera_init_param(int width, int height);
extern int read_Frame(void);
extern void closeCamera(void);

#endif

