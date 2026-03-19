#include fastmathlib.h //https://github.com/willWallace-RIT/fastmathlib.h

// Quaternion from axis-angle with fast approximations
void quat_from_axis_angle_fast(vec4 q, float angle, float ax, float ay, float az)
{
    // Normalize axis using fast rsqrt
    float len2 = fmul_fast(ax,ax) + fmul_fast(ay,ay) + fmul_fast(az,az);
    if (len2 == 0.0f) { q[0]=0; q[1]=0; q[2]=0; q[3]=1; return; }
    float inv_len = frsqrt_fast(len2); // approximate 1/sqrt(len2)
    ax = fmul_fast(ax, inv_len);
    ay = fmul_fast(ay, inv_len);
    az = fmul_fast(az, inv_len);

    float half = 0.5f * angle;
    float s = fsine_fast(half);
    float c = fcos_fast(half);

    q[0] = fmul_fast(ax, s);
    q[1] = fmul_fast(ay, s);
    q[2] = fmul_fast(az, s);
    q[3] = c;
}
