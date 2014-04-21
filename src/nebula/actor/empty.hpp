#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_EMPTY_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_EMPTY_HPP__

#include <memory>


//#include <tinyxml/tinyxml.h>

#include <math/transform.hpp>


#include <PxPhysicsAPI.h>

#include <nebula/actor/Base.hpp>

#include <gru/actor/desc.hpp>
#include <gru/actor/actor.hpp>

namespace neb {
	namespace actor {
		class empty: public neb::actor::Base {
			public:
				empty(glutpp::actor::parent_s);
				
				virtual void			init(glutpp::actor::desc_s);

				virtual void			add_force(double) {}

		};
	}
}


#endif


