/*
 * resource.c
 *
 * Copyright (C) 2012, 2013 James Booth <boothj5@gmail.com>
 *
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <common.h>
#include <resource.h>

Resource * resource_new(const char * const name, const char * const show,
    const char * const status, const int priority, const char * const caps_str)
{
    assert(g_strcmp0(show, "offline") != 0);
    assert(name != NULL);
    Resource *new_resource = malloc(sizeof(struct resource_t));
    new_resource->name = strdup(name);
    if (show == NULL || (strcmp(show, "") == 0))
        new_resource->show = strdup("online");
    else
        new_resource->show = strdup(show);
    if (status != NULL) {
        new_resource->status = strdup(status);
    } else {
        new_resource->status = NULL;
    }
    new_resource->priority = priority;
    if (caps_str != NULL) {
        new_resource->caps_str = strdup(caps_str);
    } else {
        new_resource->caps_str = NULL;
    }

    return new_resource;
}

void resource_destroy(Resource *resource)
{
    assert(resource != NULL);
    FREE_SET_NULL(resource->name);
    FREE_SET_NULL(resource->show);
    FREE_SET_NULL(resource->status);
    FREE_SET_NULL(resource->caps_str);
    FREE_SET_NULL(resource);
}
