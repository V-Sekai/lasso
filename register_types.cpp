#include "register_types.h"

#include "core/object/class_db.h"
#include "lasso.h"

void register_lasso_types() {
	ClassDB::register_class<LassoDB>();
	ClassDB::register_class<LassoPoint>();
}

void unregister_lasso_types() {
}