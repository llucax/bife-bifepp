// vim: set expandtab tabstop=4 shiftwidth=4:

#ifndef BIFE_PARSER_H
#define BIFE_PARSER_H

#include "libbife/hit.h"
#include "libbife/hash.h"
#include "libbife/widget.h"
#include "libbife/fallback.h"
#include <libxml++/libxml++.h>
#include <string>
#include <stack>

namespace bife {

    using std::string;

    /**
     * Base Widget Class.
     *
     * @todo Better plug-in support. Cleanning (a lot).
     * @todo Try to free some memeory :)
     */
    class Parser: public xmlpp::SaxParser {
        // Typedefs.
        protected:
            /// Stack of widget pointers.
            typedef std::stack<Widget*> WidgetStack;

        // Attributes.
        protected:
            /**
             * Widget stack.
             * This is the stack of widgets to know what widget is the parser
             * proccesing.
             */
            WidgetStack stack;

            /// Fallback constructor function pointer.
            Fallback::Constructor* fbNew;

            /// Fallback destructor function pointer.
            Widget::Destructor* fbDel;

            /// Fallback class name.
            string fbClass;

        public:
            /// Widget attributes (FIXME - this must be protected?).
            Widget* root;

        // Methods.
        protected:
            /**
             * Start document handler.
             */
            virtual void on_start_document(void);

            /**
             * End document handler.
             */
            virtual void on_end_document(void);

            /**
             * Start element handler.
             *
             * @param  name  Element name.
             * @param  attrs Element attributes.
             */
            virtual void on_start_element(const string&, const AttributeMap&);

            /**
             * End element handler.
             *
             * @param name Element name.
             */
            virtual void on_end_element(const string&);

            /**
             * Character handler.
             *
             * @param chars Characters.
             */
            virtual void on_characters(const string&);

            /**
             * Comment handler.
             *
             * @param text Comment text.
             */
            virtual void on_comment(const string&);

            /**
             * Warning handler.
             *
             * @param warn Warning description.
             */
            virtual void on_warning(const string&);

            /**
             * Error handler.
             *
             * @param error Error description.
             */
            virtual void on_error(const string&);

            /**
             * Fatal error handler.
             *
             * @param error Fatal error description.
             */
            virtual void on_fatal_error(const string&);

            /**
             * Validity error handler.
             *
             * @param error Validity error description.
             */
            virtual void on_validity_error(const string&);

            /**
             * Validity warning handler.
             *
             * @param warn Validity warning description.
             */
            virtual void on_validity_warning(const string&);

        public:
            /**
             * Constructor.
             */
            //Parser(void);

            /**
             * Constructor.
             *
             * @param fallback Fallback class name.
             */
            Parser(const string& = "");

            /**
             * Destructor.
             */
            virtual ~Parser(void);

            /**
             * Renders the widget using a HIT template.
             *
             * @param  hit HIT template to use to render de widget.
             * @return Rendered widget.
             */
            //virtual operator string(void) const;
    };

}

#endif
