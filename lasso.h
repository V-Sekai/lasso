#ifndef LASSODB_H
#define LASSODB_H
#ifndef _3D_DISABLED

#include "core/object/object.h"
#include "core/object/ref_counted.h"
#include "core/variant/variant.h"
#include "scene/3d/node_3d.h"

#include <memory>
#include <vector>

class LassoDB;

class LassoPoint : public RefCounted {
	GDCLASS(LassoPoint, RefCounted);

	Node3D *origin = nullptr;
	float last_snap_score = 0.0;
	Ref<LassoDB> database;

public:
	float snapping_power = 1.0;
	bool snapping_enabled = true;
	bool snap_locked = true;
	float size = 0.3;
	LassoPoint();
	~LassoPoint();
	void register_point(Ref<LassoDB> p_database, Node *p_origin);
	void unregister_point();
	float get_snap_score();
	void set_snap_score(float score);
	Vector3 get_origin_pos();
	Node *get_origin();
	bool valid_origin();
	bool matching_origin(Node *p_origin);
	static void _bind_methods();
	void enable_snapping(bool on);
	bool get_snapping_enabled();
	void set_snap_locked(bool p_enable);
	bool get_snap_locked();
	void set_size(float p_size);
	float get_size();
	void set_snapping_power(float p_snapping_power);
	float get_snapping_power();
};

class LassoDB : public RefCounted {
	GDCLASS(LassoDB, RefCounted);

	Array points;

public:
	LassoDB();
	~LassoDB();
	void add_point(Ref<LassoPoint> point);
	void remove_point(Ref<LassoPoint> point);
	Array calc_top_two_snapping_power(Transform3D source, Node *current_snap, float snap_max_power_increase, float snap_increase_amount, bool snap_lock);
	Node *calc_top_redirecting_power(Node *snapped_point, Transform3D viewpoint, Vector2 redirection_direction);
	static void _bind_methods();
};

#endif
#endif
