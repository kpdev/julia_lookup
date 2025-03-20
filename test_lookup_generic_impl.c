#include <stdlib.h>
#include "test_lookup_generic.h"

#ifdef BUILD_JULIA

void create_test_args(jl_value_t ***args, uint32_t nargs) {

    // Allocate arguments
    *args = (jl_value_t **)malloc(nargs * sizeof(jl_value_t *));

    // Tmp pointer to tagged values
    jl_taggedvalue_t* v = NULL;

    // Generate types
    jl_int32_type = (jl_datatype_t*)malloc(sizeof(jl_taggedvalue_t) + sizeof(jl_datatype_t));
    v = (jl_taggedvalue_t*)jl_int32_type;
    v->header = ((jl_datatype_tag << 4) & ~(uintptr_t)(15));
    v->type = NULL;
    jl_int32_type = (jl_datatype_t*)((char*)(jl_int32_type) + sizeof(jl_taggedvalue_t));
    jl_int32_type->hash = 1;

    jl_float64_type = (jl_datatype_t*)malloc(sizeof(jl_taggedvalue_t) + sizeof(jl_datatype_t));
    v = (jl_taggedvalue_t*)jl_float64_type;
    v->header = ((jl_datatype_tag << 4) & ~(uintptr_t)(15));
    v->type = NULL;
    jl_float64_type = (jl_datatype_t*)((char*)(jl_float64_type) + sizeof(jl_taggedvalue_t));
    jl_float64_type->hash = 2;

    jl_any_type = (jl_datatype_t*)malloc(sizeof(jl_taggedvalue_t) + sizeof(jl_datatype_t));
    v = (jl_taggedvalue_t*)jl_any_type;
    v->header = ((jl_datatype_tag << 4) & ~(uintptr_t)(15));
    v->type = NULL;
    jl_any_type = (jl_datatype_t*)((char*)(jl_any_type) + sizeof(jl_taggedvalue_t));
    jl_any_type->hash = 3;

    // p ((jl_taggedvalue_t*)((char*)(jl_int32_type) - sizeof(jl_taggedvalue_t)))
    // Заполняем массив примерными значениями
    for (uint32_t i = 0; i < nargs; i++) {
        if (i == 0) {
            (*args)[i] = (jl_value_t *)jl_int32_type; // Первый аргумент: Int32
        } else if (i == 1) {
            (*args)[i] = (jl_value_t *)jl_float64_type; // Второй аргумент: Float64
        } else {
            (*args)[i] = (jl_value_t *)jl_any_type; // Дополнительные аргументы: Any
        }
    }
}


extern jl_methtable_t* mt_mock_data;
extern jl_array_t* jl_an_empty_vec_any_mock_data;
extern jl_datatype_t* jl_typemap_level_type_mock_data;


void init_mock_data_for_test(int num_of_args, jl_value_t ** F, jl_value_t **args)
{
    mt_mock_data = malloc(sizeof(jl_methtable_t));
    mt_mock_data->leafcache = malloc(sizeof(jl_array_t));
    mt_mock_data->cache = malloc(sizeof(jl_typemap_entry_t));
    ((jl_typemap_entry_t*)mt_mock_data->cache)->sig = malloc(sizeof(jl_tuple_type));
    jl_svec_t* mock_params = malloc(sizeof(jl_svec_t) + num_of_args * sizeof(jl_value_t *));
    jl_value_t** mock_params_values = jl_svec_data(mock_params);
    for (int i = 0; i < num_of_args; ++i) {
        mock_params_values[i] = args[i];
        jl_taggedvalue_t* v = jl_astaggedvalue(args[i]);
        v->header = ((jl_datatype_tag << 4) & ~(uintptr_t)(15));
        if (jl_is_datatype(v)) {
            v->type = NULL;
        }
    }
    mock_params->length = num_of_args;
    ((jl_typemap_entry_t*)mt_mock_data->cache)->sig->parameters = mock_params;

    jl_an_empty_vec_any_mock_data = malloc(sizeof(jl_array_t));
    jl_typemap_level_type_mock_data = malloc(sizeof(jl_datatype_t));

    *F = malloc(sizeof(jl_value_t));
    ((jl_datatype_t*)*F)->parameters = mock_params;
    ((jl_datatype_t*)*F)->name = malloc(sizeof(jl_typename_t));
}

#endif

volatile int collide_default = 0, collide_sa = 0;
void MultiMethodCollide<struct Object* f1, struct Object* f2>() { collide_default++; }
void MultiMethodCollide<struct Object.Spaceship* f1, struct Object.Asteroid* f2>() { collide_sa++; }


volatile int collide_default_3d = 0, collide_saa_3d = 0;
void MultiMethodCollide3D<struct Object* f1,
                          struct Object* f2,
                          struct Object* f3>()
{
    collide_default_3d++;
}

void MultiMethodCollide3D<struct Object.Spaceship* f1,
                          struct Object.Asteroid* f2,
                          struct Object.Asteroid* f3>()
{
    collide_saa_3d++;
}

volatile int collide_default_5d = 0, collide_saaaa_5d = 0;

void MultiMethodCollide5D<struct Object* f1,
                          struct Object* f2,
                          struct Object* f3,
                          struct Object* f4,
                          struct Object* f5>()
{
    collide_default_5d++;
}

void MultiMethodCollide5D<struct Object.Spaceship* f1,
                          struct Object.Asteroid* f2,
                          struct Object.Asteroid* f3,
                          struct Object.Asteroid* f4,
                          struct Object.Asteroid* f5>()
{
    collide_saaaa_5d++;
}

Figure.rect g_fr;
Figure.trian g_ft;

struct Figure* get_figure(int i)
{
    if (i == 1) {
        return (struct Figure*)&g_fr;
    }
    if (i == 2) {
        return (struct Figure*)&g_ft;
    }

    exit(EXIT_FAILURE);
}

Object.Spaceship g_os;
Object.Asteroid  g_oa;

struct Object* get_space_object(int i)
{
    if (i == 1) {
        return (struct Object*)&g_os;
    }
    if (i == 2) {
        return (struct Object*)&g_oa;
    }

    exit(EXIT_FAILURE);
}
