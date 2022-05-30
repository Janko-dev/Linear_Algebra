#include <stdio.h>
#include <stdlib.h>
#include "../lacg.h"

#define VERTEX_SIZE 8

int main(int argc, char** argv){
    (void)argc; (void) argv;

    // Model points
    Vec4 points[VERTEX_SIZE] = {
        { .x = 0, .y = 0, .z = 0, .h = 1 },
        { .x = 1, .y = 0, .z = 0, .h = 1 },
        { .x = 1, .y = 1, .z = 0, .h = 1 },
        { .x = 0, .y = 1, .z = 0, .h = 1 },
        { .x = 0, .y = 0, .z = 1, .h = 1 },
        { .x = 1, .y = 0, .z = 1, .h = 1 },
        { .x = 1, .y = 1, .z = 1, .h = 1 },
        { .x = 0, .y = 1, .z = 1, .h = 1 }
    };

    // Model transform (0, 0, 2)
    for (int i = 0; i < VERTEX_SIZE; i++){
        add_vec4(&points[i], (Vec4){.x=0, .y=0, .z=2, .h=0});
    }

    // Center of projection (COP) and View up Vector (VUV)
    Vec3 COP = {.x = 4.f, .y = 2.f, .z = 0.f};
    Vec3 VUV = {.x = 0,   .y = 0,   .z = 1.f};
    
    // World coordinate transform, 
    // Rotation matrix, 
    // Transform -COP matrix
    Mat4x4 w_trans, R, T_COP;
    
    // Transform -COP matrix
    // 1  0  0 -4
    // 0  1  0 -2
    // 0  0  1  0
    // 0  0  0  1
    iden4(&T_COP);
    T_COP.d[0][3] = -COP.d[0];
    T_COP.d[1][3] = -COP.d[1];
    T_COP.d[2][3] = -COP.d[2];

    // u, v, w vectors
    Vec3 u, v, w = {.x = COP.x, .y = COP.y, .z = COP.z};
    scale_vec3(&w, 1/mag3(COP));
    cross_prod3(&u, VUV, w);
    cross_prod3(&v, w, u);

    // Rotation matrix
    // ux uy uz 0
    // vx vy vz 0
    // wx wy wz 0
    //  0  0  0 1
    iden4(&R);
    for (int i = 0; i < 3; i++){
        R.d[0][i] = u.d[i];
        R.d[1][i] = v.d[i];
        R.d[2][i] = w.d[i];
    }
    
    // World coordinate transform
    // R dot T_COP
    fill_mat4(&w_trans, 0);
    prod_mat4(&w_trans, R, T_COP);

    float d = 2;
    for (int i = 0; i < VERTEX_SIZE; i++){
        // Apply world coordinate transform to model
        Vec4 v = {.x=0, .y=0, .z=0, .h=0};
        prod_mat_vec4(&v, w_trans, points[i]);
        points[i] = v;

        // Perspective transform matrix
        // -d/pz  0    0    0
        //   0  -d/pz  0    0
        //   0    0  -d/pz  0
        //   0    0    0    1
        Mat4x4 persp_trans;
        iden4(&persp_trans);
        scale_mat4(&persp_trans, -d/points[i].z);
        persp_trans.d[3][3] = 1.f;

        // Apply perspective transform matrix to model
        v = (Vec4){.x=0, .y=0, .z=0, .h=0};
        prod_mat_vec4(&v, persp_trans, points[i]);
        points[i] = v;
    }

    // print result
    for (int i = 0; i < VERTEX_SIZE; i++){
        for (int j = 0; j < 4; j++){
            printf("%9.4f ", points[i].d[j]);
        }
        printf("\n");
    }

    return 0;
}