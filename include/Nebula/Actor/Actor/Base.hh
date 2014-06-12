#ifndef __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_HPP__
#define __NEBULA_CONTENT_ACTOR_PHYSICS_ACTOR_HPP__

#include <Nebula/Util/typedef.hpp>
#include <Nebula/Actor/Base.hh>

namespace neb { namespace core { namespace actor {
namespace neb {
	namespace Actor {
		namespace Actor {
			class Base: virtual public Neb::Actor::Base {
				public:
					Base();
					Base(Neb::Actor::Util::Parent_s);
					
					virtual void			init();
					virtual void			release();
					virtual void			step(Neb::Core::TimeStep const & ts);
					
					virtual void			set_pose(mat4);
			};
		}
	}
}

#endif


