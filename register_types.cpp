#include "register_types.h"

#include "core/object/class_db.h"
#include "lasso.h"

void initialize_lasso_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<LassoDB>();
	ClassDB::register_class<LassoPoint>();
}

void uninitialize_lasso_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}
