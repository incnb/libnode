// Copyright (c) 2013 Plenluno All rights reserved.

#ifndef LIBNODE_DETAIL_HTTP_OUTGOING_MESSAGE_LIST_H_
#define LIBNODE_DETAIL_HTTP_OUTGOING_MESSAGE_LIST_H_

#include <libnode/detail/free_list.h>
#include <libnode/detail/http/outgoing_message.h>

namespace libj {
namespace node {
namespace detail {
namespace http {

inline FreeList<OutgoingMessage::Ptr>* outgoingMessageList() {
#ifdef LIBJ_USE_SP
    static FreeList<OutgoingMessage::Ptr> list(100);
#else
    static FreeList<OutgoingMessage::Ptr> list(0);
#endif
    return &list;
}

}  // namespace http
}  // namespace detail
}  // namespace node
}  // namespace libj

#endif  // LIBNODE_DETAIL_HTTP_OUTGOING_MESSAGE_LIST_H_
