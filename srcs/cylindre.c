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
	t_vec3d normal;
	t_vec3d zero_ip;
	//t_vec3d centre_after_rot;

	zero_ip = mult_matrix(rotationX(-no.obj.transform.rot.x), no.ip); // comme si l'obj a eu rot.x, y, z = 0
	zero_ip = mult_matrix(rotationY(-no.obj.transform.rot.y), zero_ip);
	zero_ip = mult_matrix(rotationZ(-no.obj.transform.rot.z), zero_ip);

	//centre_after_rot = rota_vect(no.obj.transform.transl, no.obj.transform.rot);
	normal.x = zero_ip.x - no.obj.transform.transl.x;
	normal.y = zero_ip.y - no.obj.transform.transl.y;
	normal.z = 0;
	normal.w = 1;
	normal = mult_matrix(rotationX(no.obj.transform.rot.x), normal);
	normal = mult_matrix(rotationY(no.obj.transform.rot.y), normal);
	normal = mult_matrix(rotationZ(no.obj.transform.rot.z), normal);
	return (normal);
}

/*t_vec3d	cylindre_normal_vec(t_vec3d ip, t_vec3d t)
{
	t_vec3d ret;

	ret.x = ip.x - t.x;
	ret.y = ip.y - t.y;
	ret.z = ip.z - t.z;
	ret.w = 1;
	return (ret);
}*/
