/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpcellrenderertoggle.h
 * Copyright (C) 2003-2004  Sven Neumann <sven@gimp.org>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#if !defined (__GIMP_WIDGETS_H_INSIDE__) && !defined (GIMP_WIDGETS_COMPILATION)
#error "Only <libgimpwidgets/gimpwidgets.h> can be included directly."
#endif

#ifndef __GIMP_CELL_RENDERER_TOGGLE_H__
#define __GIMP_CELL_RENDERER_TOGGLE_H__

G_BEGIN_DECLS


#define GIMP_TYPE_CELL_RENDERER_TOGGLE (gimp_cell_renderer_toggle_get_type ())
G_DECLARE_DERIVABLE_TYPE (GimpCellRendererToggle, gimp_cell_renderer_toggle, GIMP, CELL_RENDERER_TOGGLE, GtkCellRendererToggle)

struct _GimpCellRendererToggleClass
{
  GtkCellRendererToggleClass  parent_class;

  void (* clicked) (GimpCellRendererToggle *cell,
                    const gchar            *path,
                    GdkModifierType         state);

  /* Padding for future expansion */
  void (* _gimp_reserved1) (void);
  void (* _gimp_reserved2) (void);
  void (* _gimp_reserved3) (void);
  void (* _gimp_reserved4) (void);
  void (* _gimp_reserved5) (void);
  void (* _gimp_reserved6) (void);
  void (* _gimp_reserved7) (void);
  void (* _gimp_reserved8) (void);
};


GtkCellRenderer * gimp_cell_renderer_toggle_new      (const gchar *icon_name);

void    gimp_cell_renderer_toggle_clicked (GimpCellRendererToggle *cell,
                                           const gchar            *path,
                                           GdkModifierType         state);


G_END_DECLS

#endif /* __GIMP_CELL_RENDERER_TOGGLE_H__ */
