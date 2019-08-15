
#include "g_operation.h"
#include "xhash.h"


G_Operation All_G_Operation;

xht g_xht = NULL;

int glib_init()
{
	 g_xht = xhash_new(2000);
	 All_G_Operation.g_fun = NULL;
	 All_G_Operation.g_debug_json_fun = NULL;
	 
}

pG_operation_file g_open(const char *name)
{
	char filename[100];

	if(xhash_get(g_xht,name))
		return NULL;


	sprintf(filename,"/mnt/mtd/%s",name);
	FILE * file_demo = fopen(filename,"w");

	if(file_demo)
	{
		pG_operation_file pG_operation_file_tmp = (pG_operation_file)malloc(sizeof(G_operation_file));
		pG_operation_file_tmp->file_handle = file_demo;
		xhash_put(g_xht,name,pG_operation_file_tmp);
		return pG_operation_file_tmp;
	}

    //fclose(file_demo);
	return 0;
}
int g_read(pG_operation_file file,void * buffer,int maxLen)
{
	if(file)
	{
		unsigned char * bufferTmp = (unsigned char *)buffer;

		int ret = fread(bufferTmp,maxLen,1,file->file_handle);
		return ret;
	}
	return -1;
}
int g_write(pG_operation_file file,void * buffer,int maxLen)
{
	if(file)
	{
		unsigned char * bufferTmp = (unsigned char *)buffer;

		int ret = fwrite(bufferTmp,maxLen,1,file->file_handle);
		return ret;
	}
	return -1;
}
int g_close(pG_operation_file file)
{
	if(file)
	{
		xhash_zap(g_xht,file->file_name);
		int ret = fclose(file->file_handle);
		free(file);
		return ret;
	}
	return -1;
}
int g_notity(const char *name)
{
	if(All_G_Operation.g_fun)
	All_G_Operation.g_fun(name);
	return 0;
}









