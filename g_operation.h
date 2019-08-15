
#include <stdio.h>



typedef int  (*g_notity_fun)(const char *name);
//debug json to main
typedef int  (*g_debug_json_fun)(const char *name);


typedef struct g_operation_
{
	g_notity_fun g_fun;
	g_notity_fun g_debug_json_fun;
}G_Operation,*pG_Operation;



typedef struct g_operation_file
{
	char  file_name[36];
	FILE * file_handle;
}G_operation_file,*pG_operation_file;


/* Must use before g_ *  fun*/

int glib_init();
//open setting json file
/* name :json file name*/
pG_operation_file g_open(const char *name);
//open setting json file
/*file :file handle  buffer: mem   maxlen:json file len */
int g_read(pG_operation_file file,void * buffer,int maxLen);
//open setting json file
/*file :file handle  buffer: mem   maxlen:json file len */
int g_write(pG_operation_file file,void * buffer,int maxLen);
//close setting json file
/*file :file handle */
int g_close(pG_operation_file file);
/*notify main to reload param */
int g_notity(const char *name);







































