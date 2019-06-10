#ifndef _SRTL_H

#define _SRTL_H

#include <stddef.h> /* size_t */
#include "../../include/DLL/dll.h" /* it_t */

/*typedef int (*scmp_f)(const void *data, const void *key, const void *params);*/
typedef int (*sact_f)(void *data, const void *arg);

typedef struct srtl srtl_t;
typedef it_t sit_t;

/*struct srtl
{
    dll_t *list;
    cmp_f is_before;
    void *params;
}
*/

srtl_t *SrtLCreate(cmp_f is_before, const void *params);
void SrtLDestroy(srtl_t *srtl);
size_t SrtLSize(const srtl_t *srtl);
int SrtLIsEmpty(const srtl_t *srtl); /* 1 For Empty */
sit_t SrtLInsert(srtl_t *srtl, const void *data);
sit_t SrtLErase(sit_t where); /*returns the node after the one removed*/ 
void SrtLPopFront(srtl_t *srtl);
void SrtLPopBack(srtl_t *srtl);
sit_t SrtLFind(sit_t from, sit_t to, cmp_f compare, const void *params, const void *key); /* returns to if not found */
int SrtLForEach(sit_t from, sit_t to, sact_f action, void *params); /* returns 0 on success, Don't change the sorting field */
sit_t SrtLBegin(const srtl_t *srtl);
sit_t SrtLEnd(const srtl_t *srtl);
sit_t SrtLNext(const sit_t iter); /* do not pass SrtLEnd ("end of srtl") as 'iter' */
sit_t SrtLPrev(const sit_t iter); /* do not pass SrtLEnd ("end of srtl") as 'iter' */
void *SrtLGetData(const sit_t iter);
int SrtLIsSame(const sit_t iter1, const sit_t iter2);
void SrtLMerge(srtl_t *dest, srtl_t *src); /* 2 Lists with the same params */

#endif
