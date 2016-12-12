#include "rt.h"

float	cylindre_dist(t_ray r)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = r.dir.x * r.dir.x + r.dir.y * r.dir.y;
	b = 2 * (r.origin.x * r.dir.x) + 2 * (r.origin.y * r.dir.y);
	c = (r.origin.x * r.origin.x) + (r.origin.y * r.origin.y) - 1;
	d = (b * b) - (4 * a * c);

	if (d >= 0)
		return (compute_solution(a, b, d));
	else
		return (-1);
}

t_vec3d		cylindre_normal_vec(t_no no)
{
	t_vec3d ret;
	t_vec3d new;

	new = mult_matrix(rotationX(-no.obj.transform.rot.x), no.ip); // comme si l'obj a eu rot.x, y, z = 0
	new = mult_matrix(rotationY(-no.obj.transform.rot.y), new);
	new = mult_matrix(rotationZ(-no.obj.transform.rot.z), new);

	ret.x = new.x - no.obj.transform.transl.x;
	ret.y = new.y - no.obj.transform.transl.y;
	ret.z = 0;
	ret.w = 1;
	return (ret);
}
