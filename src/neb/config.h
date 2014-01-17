#ifndef __NEBULA_CONFIG_H__
#define __NEBULA_CONFIG_H__

#define NEB_INSTALL_DIR "/usr/local"

#define NEBULA_DEBUG_0_FUNCTION printf("%s\n", __PRETTY_FUNCTION__)
#define NEBULA_DEBUG_1_FUNCTION //printf("%s\n", __PRETTY_FUNCTION__)

#include <memory>

#include <gal/map.h>

namespace neb
{
	class shape;

	namespace timer {
		class actor;
		typedef std::shared_ptr<actor>		actor_s;
	}
	namespace network {
		class server;
		class client;
		typedef std::shared_ptr<server>		server_s;
		typedef std::shared_ptr<client>		client_s;

		namespace control {
			namespace rigid_body {
				class create;

				class update;
				typedef std::shared_ptr<update>		update_s;
			}
		}
	}
	namespace packet
	{
		struct packet;
	}
	namespace active_transform
	{
		struct node_raw;
		class node;
		struct set_raw;
		class set;
	}

	enum flag {
		SHOULD_RELEASE = 1 << 0,
	};
	class app;
	typedef std::shared_ptr<app>	app_s;
	typedef std::weak_ptr<app>	app_w;

	namespace scene
	{
		class scene;
		typedef std::shared_ptr<scene>	scene_s;
		typedef std::weak_ptr<scene>	scene_w;
		typedef gal::map<scene>		scene_m;
	}
	class simulation_callback;
	namespace actor
	{
		class Base;
		class Actor;
		class Rigid_Actor;
		namespace rigid_body {
			class rigid_body;
			typedef std::shared_ptr<rigid_body>	rigid_body_s;
		}
		class Rigid_Dynamic;
		class Rigid_Static;
		class empty;


		typedef std::shared_ptr<Base>	Base_s;
		typedef std::weak_ptr<Base>	Base_w;
	}
	namespace control {
		namespace rigid_body {
			enum type {
				NONE = 0,
				T0,
				T1,
			};

			class raw;
			typedef std::shared_ptr<raw>		raw_s;

			class control;
			typedef std::shared_ptr<control>	control_s;

		}
	}
}

#endif



