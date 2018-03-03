#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#pragma warning(disable : 4996)

#pragma data_seg("TWH.ShareData")
unsigned int dwBugFileFlag = 0;
#pragma data_seg()
#pragma comment(linker, "/section:TWH.ShareData,rws")

namespace base 
{

	void Log(int nBugFileID,const char * format,...)
	{
		char bugFileName[12] = "cchlog0.log" ;
		char buf[256];
		FILE * fpBug;

		bugFileName[6] = '0'+ nBugFileID ;
		if( 0 == (dwBugFileFlag & ( 1<<nBugFileID ))) {
			dwBugFileFlag |= 1 << nBugFileID ;
			fpBug = fopen(bugFileName,"w");
			if( fpBug )
				fprintf(fpBug,"cchlog version 1.0\n");
		}
		else {
			fpBug = fopen(bugFileName,"a");
		}
		va_list ap;
		va_start(ap, format);
		vsprintf_s(buf, format, ap);
		va_end(ap);

		if ( fpBug ) {
			fprintf(fpBug,"%s\n",buf);
			fclose(fpBug);
		}
	}

}