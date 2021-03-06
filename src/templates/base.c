// WARNING: this file was generated automatically by balde-template-gen

#include <balde.h>
#include <glib.h>
#include <stdio.h>

extern gchar* balde_str_template_base(balde_app_t *app, balde_request_t *request, balde_response_t *response);
extern void balde_template_base(balde_app_t *app, balde_request_t *request, balde_response_t *response);

void
ba_table(balde_app_t *app, GString *resp)
{
  FILE *db = fopen("database.db", "r");
  
  char line[256];
  while(fgets(line, 256, db)) {
    gchar *row = g_strdup_printf(
        "<p style=\"color:white\">%s</p>"
        , line);
    g_string_append(resp,row);
  }
  fclose(db);
}

gchar*
balde_str_template_base(balde_app_t *app, balde_request_t *request, balde_response_t *response)
{
    GString *rv = g_string_new("");
    gchar *tmp;
    g_string_append(rv, "<html>\n    <head>\n        <title>");
    g_string_append(rv, balde_response_get_tmpl_var_or_empty(response, "title"));
    g_string_append(rv, "</title>\n        <link type=\"text/css\" rel=\"stylesheet\" href=\"");
    tmp = balde_tmpl_url_for(app, request, "static", FALSE, "screen.css");
    g_string_append(rv, tmp);
    g_free(tmp);
    g_string_append(rv, "\" />\n    </head>\n    <body>\n");
    g_string_append(rv, "<div style=\"display:flex\">");
    g_string_append(rv, "<img src=\"http://66.media.tumblr.com/f93c9acfc3846a46a47d90a339a8a59d/tumblr_nd5isu0pJc1qksk74o1_400.gif\"/>");
    g_string_append(rv, "<img src=\"http://i.giphy.com/eCqFYAVjjDksg.gif\"/>");
    g_string_append(rv, "<img src=\"http://i.imgur.com/qk6eu.gif\"/>");
    g_string_append(rv, "</div>");
    ba_table(app, rv);
    g_string_append(rv, "</body>\n</html>\n");
    return g_string_free(rv, FALSE);
}

void
balde_template_base(balde_app_t *app, balde_request_t *request, balde_response_t *response)
{
    gchar *rv = balde_str_template_base(app, request, response);
    balde_response_append_body(response, rv);
    g_free(rv);
}
