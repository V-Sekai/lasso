#include "register_types.h"

#include "core/class_db.h"
#include "lasso.h"
// #include "lasso_point.h"

void register_lasso_types() {
	ClassDB::register_class<LassoDB>();
	ClassDB::register_class<LassoPoint>();
}

void unregister_lasso_types() {
	// Nothing to do here in this example.
}