/*
 * tools/perf/util/include/linux/list.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <linux/kernel.h>
#include <linux/prefetch.h>

#include "../../../../include/linux/list.h"

#ifndef PERF_LIST_H
#define PERF_LIST_H
/**
 * list_del_range - deletes range of entries from list.
 * @begin: first element in the range to delete from the list.
 * @end: last element in the range to delete from the list.
 * Note: list_empty on the range of entries does not return true after this,
 * the entries is in an undefined state.
 */
static inline void list_del_range(struct list_head *begin,
				  struct list_head *end)
{
	begin->prev->next = end->next;
	end->next->prev = begin->prev;
}

/**
 * list_for_each_from	-	iterate over a list from one of its nodes
 * @pos:  the &struct list_head to use as a loop cursor, from where to start
 * @head: the head for your list.
 */
#define list_for_each_from(pos, head) \
	for (; pos != (head); pos = pos->next)
#endif
