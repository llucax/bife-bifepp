// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_CONTAINER_H
#define BIFE_CONTAINER_H

#include "widget.h"
#include "hit.h"
#include "hash.h"
#include <vector>
#include <string>

namespace bife {

    using std::string;

    /**
     * Base Container Class.
     *
     * @todo 
     */
    class Container: public Widget {
        // Typedefs
        protected:
            typedef std::vector<Widget> Content;

        // Attributes.
        protected:
            /// Content.
            Content content;

        // Methods.
        public:
            /**
             * Constructor.
             */
            Container(void);

            /**
             * Constructor.
             *
             * @param attrs Widget attributes.
             */
            Container(Hash);

            /**
             * Constructor.
             *
             * @param attrs   Widget attributes.
             * @param content Content of the widget.
             */
            Container(Hash, Widget&);

            /**
             * Constructor.
             *
             * @param content Content of the widget.
             * @param attrs   Widget attributes.
             */
            Container(Widget&, Hash);

            /**
             * Destructor.
             */
            virtual ~Container(void);

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            virtual string render(HIT&) = 0;

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            string renderContent(HIT&);
    };

}

#endif
