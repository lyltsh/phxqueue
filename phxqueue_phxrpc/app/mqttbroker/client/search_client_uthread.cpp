/* search_client.cpp

 Generated by phxrpc_pb2client from search.proto

*/



#include "search_client_uthread.h"

#include <cstdlib>
#include <memory>
#include <mutex>

#include "phxrpc/http.h"
#include "phxrpc/rpc.h"

#include "phxrpc_search_stub.h"
#include "resource_pool.h"


using namespace std;


static phxrpc::ClientConfig global_searchclientuthread_config_;
static phxrpc::ClientMonitorPtr global_searchclientuthread_monitor_;


bool SearchClientUThread::Init(const char *config_file) {
    return global_searchclientuthread_config_.Read(config_file);
}

const char *SearchClientUThread::GetPackageName() {
    const char *ret{global_searchclientuthread_config_.GetPackageName()};
    if (strlen(ret) == 0) {
        ret = "search";
    }
    return ret;
}

SearchClientUThread::SearchClientUThread(phxrpc::UThreadEpollScheduler *uthread_scheduler) {
    uthread_scheduler_ = uthread_scheduler;
    static mutex monitor_mutex;
    if (!global_searchclientuthread_monitor_.get()) {
        monitor_mutex.lock();
        if (!global_searchclientuthread_monitor_.get()) {
            global_searchclientuthread_monitor_ = phxrpc::MonitorFactory::GetFactory()->
                    CreateClientMonitor(GetPackageName());
        }
        global_searchclientuthread_config_.SetClientMonitor(global_searchclientuthread_monitor_);
        monitor_mutex.unlock();
    }
}

SearchClientUThread::~SearchClientUThread() {
}

// http protocol

int SearchClientUThread::PHXEcho(const google::protobuf::StringValue &req,
                                 google::protobuf::StringValue *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PHXEcho(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxHttpPublish(const phxqueue_phxrpc::mqttbroker::HttpPublishPb &req,
                                        phxqueue_phxrpc::mqttbroker::HttpPubackPb *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxHttpPublish(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

// mqtt protocol

int SearchClientUThread::PhxMqttConnect(const phxqueue_phxrpc::mqttbroker::MqttConnectPb &req,
                                        phxqueue_phxrpc::mqttbroker::MqttConnackPb *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttConnect(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPublish(const phxqueue_phxrpc::mqttbroker::MqttPublishPb &req,
                                        google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPublish(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPuback(const phxqueue_phxrpc::mqttbroker::MqttPubackPb &req,
                                       google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPuback(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPubrec(const phxqueue_phxrpc::mqttbroker::MqttPubrecPb &req,
                                       google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPubrec(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPubrel(const phxqueue_phxrpc::mqttbroker::MqttPubrelPb &req,
                                       google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPubrel(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPubcomp(const phxqueue_phxrpc::mqttbroker::MqttPubcompPb &req,
                                        google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPubcomp(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttSubscribe(const phxqueue_phxrpc::mqttbroker::MqttSubscribePb &req,
                                          phxqueue_phxrpc::mqttbroker::MqttSubackPb *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttSubscribe(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttUnsubscribe(const phxqueue_phxrpc::mqttbroker::MqttUnsubscribePb &req,
                                            phxqueue_phxrpc::mqttbroker::MqttUnsubackPb *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttUnsubscribe(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttPing(const phxqueue_phxrpc::mqttbroker::MqttPingreqPb &req,
                                     phxqueue_phxrpc::mqttbroker::MqttPingrespPb *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttPing(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

int SearchClientUThread::PhxMqttDisconnect(const phxqueue_phxrpc::mqttbroker::MqttDisconnectPb &req,
                                           google::protobuf::Empty *resp) {
    const phxrpc::Endpoint_t *ep = global_searchclientuthread_config_.GetRandom();

    if (uthread_scheduler_ && ep) {
        auto &&socket_pool(ResourcePool<uint64_t, phxrpc::UThreadTcpStream>::GetInstance());
        // TODO:
        uint64_t key(ep->port);
        auto socket = move(socket_pool->Get(key));

        if (nullptr == socket.get()) {
            socket.reset(new phxrpc::UThreadTcpStream());

            bool open_ret{phxrpc::PhxrpcTcpUtils::Open(uthread_scheduler_, socket.get(), ep->ip, ep->port,
                    global_searchclientuthread_config_.GetConnectTimeoutMS(),
                    *(global_searchclientuthread_monitor_.get()))};
            if (!open_ret) {
                phxrpc::log(LOG_ERR, "Open %s:%d err %d", ep->ip, ep->port, open_ret);

                return -1;
            }
            socket->SetTimeout(global_searchclientuthread_config_.GetSocketTimeoutMS());
        }

        phxrpc::HttpMessageHandlerFactory http_msg_factory;
        SearchStub stub(*(socket.get()), *(global_searchclientuthread_monitor_.get()), http_msg_factory);
        int ret{stub.PhxMqttDisconnect(req, resp)};
        socket_pool->Put(key, socket);

        return ret;
    }

    return -1;
}

