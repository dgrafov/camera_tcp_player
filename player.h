
#ifndef PLAYER_H_
#define PLAYER_H_

#include <gst/gst.h>
#include <glib.h>
#include <memory>
#include <string>

#include "config-manager.h"

class Player {
public:
    Player();  
    ~Player();
    void startPlayer();
    void loadConfig(const std::string & filename = "");
private:
    static gboolean busCallHandlerWrapper (GstBus *bus, 
            GstMessage *msg, 
            gpointer data);

    gboolean busCallHandler(GstBus *bus, 
            GstMessage *msg, 
            gpointer data);

    std::shared_ptr<GMainLoop> loopSp;
    std::shared_ptr<GstElement> pipelineSp;
    std::shared_ptr<GstElement> sourceSp;
    std::shared_ptr<GstElement> encoderSp;
    std::shared_ptr<GstElement> muxerSp;
    std::shared_ptr<GstElement> sinkSp;
    std::shared_ptr<GstElement> filterSp;

    guint busWatchId;
    ConfigManager cm;

};


#endif /* PLAYER_H_ */
