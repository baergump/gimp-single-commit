/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpchannel_pdb.h
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

#ifndef __GIMP_CHANNEL_PDB_H__
#define __GIMP_CHANNEL_PDB_H__

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


G_GNUC_INTERNAL GimpChannel* _gimp_channel_new               (GimpImage       *image,
                                                              gint             width,
                                                              gint             height,
                                                              const gchar     *name,
                                                              gdouble          opacity,
                                                              GeglColor       *color);
GimpChannel*                 gimp_channel_new_from_component (GimpImage       *image,
                                                              GimpChannelType  component,
                                                              const gchar     *name);
GimpChannel*                 gimp_channel_copy               (GimpChannel     *channel);
gboolean                     gimp_channel_combine_masks      (GimpChannel     *channel1,
                                                              GimpChannel     *channel2,
                                                              GimpChannelOps   operation,
                                                              gint             offx,
                                                              gint             offy);
gboolean                     gimp_channel_get_show_masked    (GimpChannel     *channel);
gboolean                     gimp_channel_set_show_masked    (GimpChannel     *channel,
                                                              gboolean         show_masked);
gdouble                      gimp_channel_get_opacity        (GimpChannel     *channel);
gboolean                     gimp_channel_set_opacity        (GimpChannel     *channel,
                                                              gdouble          opacity);
GeglColor*                   gimp_channel_get_color          (GimpChannel     *channel);
gboolean                     gimp_channel_set_color          (GimpChannel     *channel,
                                                              GeglColor       *color);


G_END_DECLS

#endif /* __GIMP_CHANNEL_PDB_H__ */
