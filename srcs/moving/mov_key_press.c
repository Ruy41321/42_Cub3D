/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpennisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:19:27 by lpennisi          #+#    #+#             */
/*   Updated: 2025/02/06 16:19:28 by lpennisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/*this function manages the press of movement's player keycode
it is called by key_press() which is the call-back function managed by mlx_hook
Now, Questa funzioine è void ed ha due parametri perchè per costruzione fornisc
elementi di informazioni alla funzione di coll_back che ora abbiao citato.
La funzione di callback non può essere diversa da come è in termini di firma. 
E quindi a cascata questa funzione anche è cosi.
deve avere un keycode. Questa funzione gestisceil keycode che le viene passato.
se il keycode è di un certo tipo allora setta il movimento del player.

*/
static void	mov_key_press_position(int keycode, t_c3d *c3d)
{
	if (keycode == KEY_W)
		c3d->player.move.w = 1;
	if (keycode == KEY_S)
		c3d->player.move.s = 1;
	if (keycode == KEY_A)
		c3d->player.move.a = 1;
	if (keycode == KEY_D)
		c3d->player.move.d = 1;
}

/*it is called by key_press which is the call-back function managed by mlx_hook
vedi spiegazione di keypress_playerposition*/
static void	mov_key_press_rotation(int keycode, t_c3d *c3d)
{
	if (keycode == ARROW_RIGHT)
		c3d->player.rotate_alpha_right = 1;
	if (keycode == ARROW_LEFT)
		c3d->player.rotate_alpha_left = 1;
}

/*this function has to be this sign becouse it is called in mlx_hook
in altri termini è obbligatorio avere un parametro int e uno void*.
Al parametro int è passato il keycode dalla funzione mlx_hook.
Quella funziona attualmente è impaostat acon un codice evento
(Che non è il keycode)
2. il codice evento 2 indiche che quella funzione è in ascolto sugli eventi di
pressione della tastiera.
Ecco quindi che restituirà il keycode(codice tel tasto della tastiera)
che è stato pigiato.
Ecco quindi che la palla passa alle funzioni che keypress ha internamente.
In pratica key_press riceve il keycode.
e successivamente il keycode è gestito da key_oress playerposiziont
 e keypressplayer direction
*/
int	mov_key_press(int keycode, void *param)
{
	t_c3d	*c3d;

	c3d = (t_c3d *)param;
	if (keycode == ESC)
		on_destroy(c3d);
	mov_key_press_position(keycode, c3d);
	mov_key_press_rotation(keycode, c3d);
	return (0);
}
