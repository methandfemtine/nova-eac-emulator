#pragma once

#include <common/api/request.h>
#include <common/api/response.h>
#include <common/api/session_id.h>
#include <plog/Log.h>

#include <unordered_map>

#include "id2string_handler.h"
#include "login_handler.h"
#include "login_status_handler.h"

class api_handler_registry {
	typedef std::shared_ptr<response>(*HandlerFuncPtr)(std::shared_ptr<request>);
	static inline std::unordered_map<int, HandlerFuncPtr> handlers;

public:
	static void init() {
		handlers[ID2STRING_REQ_ID] = id2string_handler::handle;
		handlers[LOGIN_REQ_ID] = login_handler::handle;
		handlers[LOGIN_STATUS_REQ_ID] = login_status_handler::handle;

		PLOGD.printf("Collected %d handlers", handlers.size());
	}

	static HandlerFuncPtr get_handler_by_id(unsigned char req_id) {
		if (!handlers.contains(req_id)) {
			PLOGE.printf("Invalid handler id specified: %d", req_id);
			return nullptr;
		}

		return handlers[req_id];
	}
};
