/*File generated during static filter build
  Automatically generated file
*/

  extern "C" IndividualFilter * new_aspell_markdown_filter();

  extern "C" IndividualFilter * new_aspell_context_filter();

  extern "C" IndividualFilter * new_aspell_html_decoder();

  extern "C" IndividualFilter * new_aspell_html_filter();

  extern "C" IndividualFilter * new_aspell_email_filter();

  extern "C" IndividualFilter * new_aspell_sgml_decoder();

  extern "C" IndividualFilter * new_aspell_sgml_filter();

  extern "C" IndividualFilter * new_aspell_url_filter();

  extern "C" IndividualFilter * new_aspell_tex_filter();

  extern "C" IndividualFilter * new_aspell_texinfo_filter();

  static FilterEntry standard_filters[] = {
    {"markdown",0,new_aspell_markdown_filter,0},
    {"context",0,new_aspell_context_filter,0},
    {"html",new_aspell_html_decoder,new_aspell_html_filter,0},
    {"email",0,new_aspell_email_filter,0},
    {"sgml",new_aspell_sgml_decoder,new_aspell_sgml_filter,0},
    {"url",0,new_aspell_url_filter,0},
    {"tex",0,new_aspell_tex_filter,0},
    {"texinfo",0,new_aspell_texinfo_filter,0}
  };

  const unsigned int standard_filters_size = sizeof(standard_filters)/sizeof(FilterEntry);

  static KeyInfo markdown_options[] = {
    {
      "f-markdown-block-start-tags",
      KeyInfoList,
      "address:article:aside:base:basefont:blockquote:body:caption:center:col:colgroup:dd:details:dialog:dir:div:dl:dt:fieldset:figcaption:figure:footer:form:frame:frameset:h1:h2:h3:h4:h5:h6:head:header:hr:html:iframe:legend:li:link:main:menu:menuitem:nav:noframes:ol:optgroup:option:p:param:section:source:summary:table:tbody:td:tfoot:th:thead:title:tr:track:ul",
      "HTML tags that start an HTML block that ends with a blank line"
    },
    {
      "f-markdown-raw-start-tags",
      KeyInfoList,
      "script:pre:style",
      "HTML tags that start an HTML block that allows blank lines"
    },
    {
      "f-markdown-skip-ref-labels",
      KeyInfoBool,
      "true",
      "skip link labels in link reference definitions"
    },
    {
      "f-markdown-multiline-tags",
      KeyInfoBool,
      "true",
      "support tags that span multiple lines outside of HTML blocks"
    }
  };

  const KeyInfo * markdown_options_begin = markdown_options;

  const KeyInfo * markdown_options_end = markdown_options+sizeof(markdown_options)/sizeof(KeyInfo);

  static KeyInfo context_options[] = {
    {
      "f-context-visible-first",
      KeyInfoBool,
      "false",
      "swaps visible and invisible text"
    },
    {
      "f-context-delimiters",
      KeyInfoList,
      "\" \":/* */:// 0",
      "context delimiters (separated by spaces)"
    }
  };

  const KeyInfo * context_options_begin = context_options;

  const KeyInfo * context_options_end = context_options+sizeof(context_options)/sizeof(KeyInfo);

  static KeyInfo html_options[] = {
    {
      "f-html-check",
      KeyInfoList,
      "alt",
      "HTML attributes to always check"
    },
    {
      "f-html-skip",
      KeyInfoList,
      "script:style",
      "HTML tags to always skip the contents of"
    }
  };

  const KeyInfo * html_options_begin = html_options;

  const KeyInfo * html_options_end = html_options+sizeof(html_options)/sizeof(KeyInfo);

  static KeyInfo email_options[] = {
    {
      "f-email-quote",
      KeyInfoList,
      ">:|",
      "email quote characters"
    },
    {
      "f-email-margin",
      KeyInfoInt,
      "10",
      "num chars that can appear before the quote char"
    }
  };

  const KeyInfo * email_options_begin = email_options;

  const KeyInfo * email_options_end = email_options+sizeof(email_options)/sizeof(KeyInfo);

  static KeyInfo sgml_options[] = {
    {
      "f-sgml-skip",
      KeyInfoList,
      "",
      "SGML tags to always skip the contents of"
    },
    {
      "f-sgml-check",
      KeyInfoList,
      "",
      "SGML attributes to always check"
    }
  };

  const KeyInfo * sgml_options_begin = sgml_options;

  const KeyInfo * sgml_options_end = sgml_options+sizeof(sgml_options)/sizeof(KeyInfo);

  static KeyInfo url_options[] = {
    {
      "f-url-url",
      KeyInfoBool,
      "none",
      ""
    }
  };

  const KeyInfo * url_options_begin = url_options;

  const KeyInfo * url_options_end = url_options+sizeof(url_options)/sizeof(KeyInfo);

  static KeyInfo tex_options[] = {
    {
      "f-tex-check-comments",
      KeyInfoBool,
      "false",
      "check TeX comments"
    },
    {
      "f-tex-command",
      KeyInfoList,
      "addtocounter pp:addtolength pp:alpha p:arabic p:fnsymbol p:roman p:stepcounter p:setcounter pp:usecounter p:value p:newcounter po:refstepcounter p:label p:pageref p:ref p:newcommand poOP:renewcommand poOP:newenvironment poOPP:renewenvironment poOPP:newtheorem poPo:newfont pp:documentclass op:usepackage op:begin po:end p:setlength pp:addtolength pp:settowidth pp:settodepth pp:settoheight pp:enlargethispage p:hyphenation p:pagenumbering p:pagestyle p:addvspace p:framebox ooP:hspace p:vspace p:makebox ooP:parbox ooopP:raisebox pooP:rule opp:sbox pO:savebox pooP:usebox p:include p:includeonly p:input p:addcontentsline ppP:addtocontents pP:fontencoding p:fontfamily p:fontseries p:fontshape p:fontsize pp:usefont pppp:documentstyle op:cite p:nocite p:psfig p:selectlanguage p:includegraphics op:bibitem op:geometry p",
      "TeX commands"
    }
  };

  const KeyInfo * tex_options_begin = tex_options;

  const KeyInfo * tex_options_end = tex_options+sizeof(tex_options)/sizeof(KeyInfo);

  static KeyInfo texinfo_options[] = {
    {
      "f-texinfo-ignore-env",
      KeyInfoList,
      "example:smallexample:verbatim:lisp:smalllisp:small:display:snalldisplay:format:smallformat",
      "Texinfo environments to ignore"
    },
    {
      "f-texinfo-ignore",
      KeyInfoList,
      "setfilename:syncodeindex:documentencoding:vskip:code:kbd:key:samp:verb:var:env:file:command:option:url:uref:email:verbatiminclude:xref:ref:pxref:inforef:c",
      "Texinfo commands to ignore the parameters of"
    }
  };

  const KeyInfo * texinfo_options_begin = texinfo_options;

  const KeyInfo * texinfo_options_end = texinfo_options+sizeof(texinfo_options)/sizeof(KeyInfo);


  static ConfigModule filter_modules[] = {
    {
      "markdown",0,
      "filter for Markdown/CommonMark documents",
      markdown_options_begin,markdown_options_end
    },
    {
      "context",0,
      "experimental filter for hiding delimited contexts",
      context_options_begin,context_options_end
    },
    {
      "html",0,
      "filter for dealing with HTML documents",
      html_options_begin,html_options_end
    },
    {
      "email",0,
      "filter for skipping quoted text in email messages",
      email_options_begin,email_options_end
    },
    {
      "sgml",0,
      "filter for dealing with generic SGML/XML documents",
      sgml_options_begin,sgml_options_end
    },
    {
      "url",0,
      "filter to skip URL like constructs",
      url_options_begin,url_options_end
    },
    {
      "tex",0,
      "filter for dealing with TeX/LaTeX documents",
      tex_options_begin,tex_options_end
    },
    {
      "texinfo",0,
      "filter for dealing with Texinfo documents",
      texinfo_options_begin,texinfo_options_end
    }
  };

  const ConfigModule * filter_modules_begin = filter_modules;

  const ConfigModule * filter_modules_end = filter_modules+sizeof(filter_modules)/sizeof(ConfigModule);

  const size_t filter_modules_size = sizeof(filter_modules);
