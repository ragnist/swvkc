#ifndef MYXDGSURFACE_H
#define MYXDGSURFACE_H

#include <wayland-server-core.h>
#include <util/box.h>

struct xdg_surface0;
typedef void (*xdg_surface_contents_update_t)(struct xdg_surface0 *, void *);

struct xdg_surface_state0 {
	struct box window_geometry;
};

struct xdg_surface0 {
	struct wl_resource *self;
	struct wl_resource *surface;
	struct wl_resource *keyboard;
	struct server *server;
	struct xdg_surface_state0 *pending, *current;
	struct wl_listener commit;
	struct wl_list link;

	struct wl_signal contents_update;

	xdg_surface_contents_update_t contents_update_callback;
	void *user_data;
};

struct xdg_surface0 *xdg_surface_new(struct wl_resource *resource, struct
wl_resource *surface_resource, struct server *server,
xdg_surface_contents_update_t xdg_surface_contents_update, void *user_data);

#endif
