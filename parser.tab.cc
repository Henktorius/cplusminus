// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 15 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_element: // program_element
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_expression_opt: // expression_opt
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_read_statement: // read_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_arguments: // arguments
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STR: // STR
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_element: // program_element
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_expression_opt: // expression_opt
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_read_statement: // read_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_arguments: // arguments
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STR: // STR
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_element: // program_element
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_expression_opt: // expression_opt
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_read_statement: // read_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_arguments: // arguments
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STR: // STR
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_element: // program_element
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_expression_opt: // expression_opt
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_read_statement: // read_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_arguments: // arguments
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STR: // STR
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_program_element: // program_element
      case symbol_kind::S_class_declaration: // class_declaration
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_class_member: // class_member
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_parameter_list: // parameter_list
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_type: // type
      case symbol_kind::S_block: // block
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_variable_declaration: // variable_declaration
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_for_statement: // for_statement
      case symbol_kind::S_expression_opt: // expression_opt
      case symbol_kind::S_return_statement: // return_statement
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_read_statement: // read_statement
      case symbol_kind::S_break_statement: // break_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_argument_list: // argument_list
      case symbol_kind::S_arguments: // arguments
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STR: // STR
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: program
#line 56 "parser.yy"
            { root = yystack_[0].value.as < Node * > (); }
#line 683 "parser.tab.cc"
    break;

  case 3: // program: program_element
#line 60 "parser.yy"
                    {
        yylhs.value.as < Node * > () = new Node("Program", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 692 "parser.tab.cc"
    break;

  case 4: // program: program program_element
#line 64 "parser.yy"
                              {
        yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 701 "parser.tab.cc"
    break;

  case 5: // program_element: class_declaration
#line 71 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 707 "parser.tab.cc"
    break;

  case 6: // program_element: function_definition
#line 72 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 713 "parser.tab.cc"
    break;

  case 7: // program_element: statement
#line 73 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 719 "parser.tab.cc"
    break;

  case 8: // class_declaration: CLASS ID LL class_body RL
#line 78 "parser.yy"
                              {
        Node* n = new Node("ClassDeclaration", yystack_[3].value.as < std::string > (), yylineno);
        n->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > () = n;
    }
#line 729 "parser.tab.cc"
    break;

  case 9: // class_body: %empty
#line 86 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("ClassBody", "", yylineno); }
#line 735 "parser.tab.cc"
    break;

  case 10: // class_body: class_body class_member
#line 87 "parser.yy"
                              {
        yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 744 "parser.tab.cc"
    break;

  case 11: // class_member: variable_declaration
#line 94 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 750 "parser.tab.cc"
    break;

  case 12: // class_member: function_definition
#line 95 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 756 "parser.tab.cc"
    break;

  case 13: // function_definition: ID LP parameter_list RP COLON type block
#line 100 "parser.yy"
                                             {
        Node* n = new Node("FunctionDefinition", yystack_[6].value.as < std::string > (), yylineno);
        n->children.push_back(yystack_[4].value.as < Node * > ()); // Parameters
        n->children.push_back(yystack_[1].value.as < Node * > ()); // Return Type
        n->children.push_back(yystack_[0].value.as < Node * > ()); // Body
        yylhs.value.as < Node * > () = n;
    }
#line 768 "parser.tab.cc"
    break;

  case 14: // parameter_list: %empty
#line 110 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno); }
#line 774 "parser.tab.cc"
    break;

  case 15: // parameter_list: parameters
#line 111 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 780 "parser.tab.cc"
    break;

  case 16: // parameters: ID COLON type
#line 115 "parser.yy"
                  {
        yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno);
        Node* p = new Node("Parameter", yystack_[2].value.as < std::string > (), yylineno);
        p->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(p);
    }
#line 791 "parser.tab.cc"
    break;

  case 17: // parameters: parameters COMMA ID COLON type
#line 121 "parser.yy"
                                     {
        Node* p = new Node("Parameter", yystack_[2].value.as < std::string > (), yylineno);
        p->children.push_back(yystack_[0].value.as < Node * > ());
        yystack_[4].value.as < Node * > ()->children.push_back(p);
        yylhs.value.as < Node * > () = yystack_[4].value.as < Node * > ();
    }
#line 802 "parser.tab.cc"
    break;

  case 18: // type: INT_T
#line 131 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Type", "int", yylineno); }
#line 808 "parser.tab.cc"
    break;

  case 19: // type: FLOAT_T
#line 132 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Type", "float", yylineno); }
#line 814 "parser.tab.cc"
    break;

  case 20: // type: BOOL_T
#line 133 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("Type", "bool", yylineno); }
#line 820 "parser.tab.cc"
    break;

  case 21: // type: VOID_T
#line 134 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("Type", "void", yylineno); }
#line 826 "parser.tab.cc"
    break;

  case 22: // type: ID
#line 135 "parser.yy"
         { yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno); }
#line 832 "parser.tab.cc"
    break;

  case 23: // type: type LS RS
#line 136 "parser.yy"
                 {
        Node* n = new Node("ArrayType", "", yylineno);
        n->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > () = n;
    }
#line 842 "parser.tab.cc"
    break;

  case 24: // block: LL statements RL
#line 145 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 848 "parser.tab.cc"
    break;

  case 25: // statements: %empty
#line 149 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("Block", "", yylineno); }
#line 854 "parser.tab.cc"
    break;

  case 26: // statements: statements statement
#line 150 "parser.yy"
                           {
        yystack_[1].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
    }
#line 863 "parser.tab.cc"
    break;

  case 27: // statement: variable_declaration
#line 157 "parser.yy"
    { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 869 "parser.tab.cc"
    break;

  case 28: // statement: assignment_statement
#line 158 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 875 "parser.tab.cc"
    break;

  case 29: // statement: if_statement
#line 159 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 881 "parser.tab.cc"
    break;

  case 30: // statement: for_statement
#line 160 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 887 "parser.tab.cc"
    break;

  case 31: // statement: return_statement
#line 161 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 893 "parser.tab.cc"
    break;

  case 32: // statement: print_statement
#line 162 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 899 "parser.tab.cc"
    break;

  case 33: // statement: read_statement
#line 163 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 905 "parser.tab.cc"
    break;

  case 34: // statement: break_statement
#line 164 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 911 "parser.tab.cc"
    break;

  case 35: // statement: expression
#line 165 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 917 "parser.tab.cc"
    break;

  case 36: // statement: block
#line 166 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 923 "parser.tab.cc"
    break;

  case 37: // variable_declaration: VOL ID COLON type
#line 170 "parser.yy"
                      {
        Node* n = new Node("VolatileDeclaration", yystack_[2].value.as < std::string > (), yylineno);
        n->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = n;
    }
#line 933 "parser.tab.cc"
    break;

  case 38: // variable_declaration: VOL ID COLON type ASS expression
#line 175 "parser.yy"
                                       {
        Node* n = new Node("VolatileDeclarationAssign", yystack_[4].value.as < std::string > (), yylineno);
        n->children.push_back(yystack_[2].value.as < Node * > ());
        n->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = n;
    }
#line 944 "parser.tab.cc"
    break;

  case 39: // assignment_statement: expression ASS expression
#line 184 "parser.yy"
                              {
        yylhs.value.as < Node * > () = new Node("Assignment", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 954 "parser.tab.cc"
    break;

  case 40: // if_statement: IF LP expression RP block
#line 192 "parser.yy"
                              {
        yylhs.value.as < Node * > () = new Node("If", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 964 "parser.tab.cc"
    break;

  case 41: // if_statement: IF LP expression RP block ELSE block
#line 197 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = new Node("IfElse", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 975 "parser.tab.cc"
    break;

  case 42: // for_statement: FOR LP expression_opt COMMA expression_opt COMMA expression_opt RP block
#line 206 "parser.yy"
                                                                             {
        yylhs.value.as < Node * > () = new Node("For", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 987 "parser.tab.cc"
    break;

  case 43: // expression_opt: %empty
#line 216 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("EmptyExpr", "", yylineno); }
#line 993 "parser.tab.cc"
    break;

  case 44: // expression_opt: expression
#line 217 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 999 "parser.tab.cc"
    break;

  case 45: // expression_opt: variable_declaration
#line 218 "parser.yy"
                           { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1005 "parser.tab.cc"
    break;

  case 46: // return_statement: RET expression
#line 222 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("Return", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1014 "parser.tab.cc"
    break;

  case 47: // print_statement: PRINT LP expression RP
#line 229 "parser.yy"
                           {
        yylhs.value.as < Node * > () = new Node("Print", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1023 "parser.tab.cc"
    break;

  case 48: // read_statement: READ LP ID RP
#line 236 "parser.yy"
                  {
        yylhs.value.as < Node * > () = new Node("Read", yystack_[1].value.as < std::string > (), yylineno);
    }
#line 1031 "parser.tab.cc"
    break;

  case 49: // break_statement: BREAK
#line 242 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Break", "", yylineno); }
#line 1037 "parser.tab.cc"
    break;

  case 50: // expression: INT
#line 247 "parser.yy"
        { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); }
#line 1043 "parser.tab.cc"
    break;

  case 51: // expression: FLOAT
#line 248 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("FloatLiteral", yystack_[0].value.as < std::string > (), yylineno); }
#line 1049 "parser.tab.cc"
    break;

  case 52: // expression: TRUE
#line 249 "parser.yy"
           { yylhs.value.as < Node * > () = new Node("BoolLiteral", "true", yylineno); }
#line 1055 "parser.tab.cc"
    break;

  case 53: // expression: FALSE
#line 250 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("BoolLiteral", "false", yylineno); }
#line 1061 "parser.tab.cc"
    break;

  case 54: // expression: ID
#line 251 "parser.yy"
         { yylhs.value.as < Node * > () = new Node("Id", yystack_[0].value.as < std::string > (), yylineno); }
#line 1067 "parser.tab.cc"
    break;

  case 55: // expression: LP expression RP
#line 252 "parser.yy"
                       { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 1073 "parser.tab.cc"
    break;

  case 56: // expression: expression PLUSOP expression
#line 254 "parser.yy"
                                   { yylhs.value.as < Node * > () = new Node("Add", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1079 "parser.tab.cc"
    break;

  case 57: // expression: expression SUBOP expression
#line 255 "parser.yy"
                                  { yylhs.value.as < Node * > () = new Node("Sub", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1085 "parser.tab.cc"
    break;

  case 58: // expression: expression MULTOP expression
#line 256 "parser.yy"
                                   { yylhs.value.as < Node * > () = new Node("Mult", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1091 "parser.tab.cc"
    break;

  case 59: // expression: expression DIVOP expression
#line 257 "parser.yy"
                                  { yylhs.value.as < Node * > () = new Node("Div", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1097 "parser.tab.cc"
    break;

  case 60: // expression: expression POW expression
#line 258 "parser.yy"
                                { yylhs.value.as < Node * > () = new Node("Pow", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1103 "parser.tab.cc"
    break;

  case 61: // expression: SUBOP expression
#line 259 "parser.yy"
                                         { yylhs.value.as < Node * > () = new Node("UnaryMinus", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1109 "parser.tab.cc"
    break;

  case 62: // expression: expression EQL expression
#line 261 "parser.yy"
                                { yylhs.value.as < Node * > () = new Node("Equal", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1115 "parser.tab.cc"
    break;

  case 63: // expression: expression NE expression
#line 262 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("NotEqual", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1121 "parser.tab.cc"
    break;

  case 64: // expression: expression LT expression
#line 263 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("Less", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1127 "parser.tab.cc"
    break;

  case 65: // expression: expression GT expression
#line 264 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("Greater", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1133 "parser.tab.cc"
    break;

  case 66: // expression: expression LTE expression
#line 265 "parser.yy"
                                { yylhs.value.as < Node * > () = new Node("LessEqual", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1139 "parser.tab.cc"
    break;

  case 67: // expression: expression GTE expression
#line 266 "parser.yy"
                                { yylhs.value.as < Node * > () = new Node("GreaterEqual", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1145 "parser.tab.cc"
    break;

  case 68: // expression: expression AND expression
#line 267 "parser.yy"
                                { yylhs.value.as < Node * > () = new Node("And", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1151 "parser.tab.cc"
    break;

  case 69: // expression: expression OR expression
#line 268 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("Or", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1157 "parser.tab.cc"
    break;

  case 70: // expression: NOT expression
#line 269 "parser.yy"
                     { yylhs.value.as < Node * > () = new Node("Not", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1163 "parser.tab.cc"
    break;

  case 71: // expression: expression LS expression RS
#line 271 "parser.yy"
                                  {
        yylhs.value.as < Node * > () = new Node("ArrayIndex", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1173 "parser.tab.cc"
    break;

  case 72: // expression: expression DOT ID
#line 276 "parser.yy"
                        {
        yylhs.value.as < Node * > () = new Node("MemberAccess", yystack_[0].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 1182 "parser.tab.cc"
    break;

  case 73: // expression: expression LP argument_list RP
#line 281 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = new Node("Call", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1192 "parser.tab.cc"
    break;

  case 74: // expression: type LS argument_list RS
#line 287 "parser.yy"
                               {
        yylhs.value.as < Node * > () = new Node("ArrayInit", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1202 "parser.tab.cc"
    break;

  case 75: // argument_list: %empty
#line 295 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("ArgumentList", "", yylineno); }
#line 1208 "parser.tab.cc"
    break;

  case 76: // argument_list: arguments
#line 296 "parser.yy"
                { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1214 "parser.tab.cc"
    break;

  case 77: // arguments: expression
#line 300 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("ArgumentList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1223 "parser.tab.cc"
    break;

  case 78: // arguments: arguments COMMA expression
#line 304 "parser.yy"
                                 {
        yystack_[2].value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
        yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
    }
#line 1232 "parser.tab.cc"
    break;


#line 1236 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -108;

  const signed char parser::yytable_ninf_ = -23;

  const short
  parser::yypact_[] =
  {
      96,   196,   196,   196,  -108,   -38,  -108,  -108,  -108,  -108,
     -35,    -7,     6,   196,  -108,     9,    16,  -108,  -108,     5,
    -108,  -108,    38,    96,  -108,  -108,  -108,    20,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,   241,    23,
      24,    24,   259,   127,    22,    27,   196,   158,   337,   196,
       7,    28,  -108,  -108,   177,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,    29,  -108,  -108,  -108,   -16,  -108,   277,  -108,    65,
     337,   295,    32,    69,    77,    78,  -108,   337,    80,    79,
     173,   173,    73,    73,    73,   337,   373,   373,    15,    15,
      15,    15,   355,    72,    85,   313,  -108,  -108,    -3,   -19,
      83,   158,  -108,  -108,   -16,    81,    62,  -108,   196,  -108,
    -108,   196,    87,  -108,    91,  -108,  -108,  -108,    76,    88,
      95,   -16,    94,   337,   337,    83,   158,    17,   -16,  -108,
      97,  -108,    95,    83,  -108
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,    25,     0,    18,    19,    20,    21,
       0,     0,     0,     0,    49,     0,     0,    52,    53,    54,
      50,    51,     0,     2,     3,     5,     6,     0,    36,     7,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    54,
      61,    70,     0,     0,     0,     0,     0,    43,    46,     0,
       0,    14,     1,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,    55,    24,    26,     0,     9,     0,    45,     0,
      44,     0,     0,     0,     0,    15,    23,    77,     0,    76,
      56,    57,    58,    59,    60,    39,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,    72,    22,    37,     0,
       0,    43,    47,    48,     0,     0,     0,    74,     0,    73,
      71,     0,     0,     8,     0,    10,    12,    11,    40,     0,
      16,     0,     0,    78,    38,     0,    43,     0,     0,    41,
       0,    13,    17,     0,    42
  };

  const signed char
  parser::yypgoto_[] =
  {
    -108,  -108,  -108,    98,  -108,  -108,  -108,    13,  -108,  -108,
     -43,  -107,  -108,   103,   -39,  -108,  -108,  -108,  -105,  -108,
    -108,  -108,  -108,    -1,    54,  -108
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    22,    23,    24,    25,   109,   125,    26,    84,    85,
      27,    28,    43,    29,    30,    31,    32,    33,    79,    34,
      35,    36,    37,    38,    88,    89
  };

  const short
  parser::yytable_[] =
  {
      40,    41,    42,   128,   123,   121,   129,    44,    78,     5,
      45,    46,    48,     6,     7,     8,     9,   122,    55,    56,
      57,    58,    59,    51,    47,   -22,   124,    49,   139,   107,
     141,   140,   108,    69,    50,    70,   144,   122,    52,     4,
      54,    71,    69,   -22,    70,    77,    80,    75,    81,    76,
      71,   113,    82,    87,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    87,   105,
     127,   130,    78,    83,   106,    55,    56,    57,    58,    59,
      59,    61,    62,    63,    64,    65,    66,    67,   137,   111,
      69,    69,    70,    70,   114,   142,   115,    78,    71,    71,
       1,   117,   116,   118,   119,     4,   131,   132,    86,    51,
      80,   135,   136,     2,     3,   122,   143,   133,     4,   138,
     134,    53,   126,   104,     5,     6,     7,     8,     9,    10,
      11,     1,    12,    13,    14,    80,    15,    16,     0,    17,
      18,    19,    20,    21,     2,     3,    74,     0,     0,     4,
      73,     0,     0,     0,     0,     5,     6,     7,     8,     9,
       0,    11,     1,    12,    13,    14,     0,    15,    16,     0,
      17,    18,    39,    20,    21,     2,     3,     0,    57,    58,
      59,     1,     0,     0,     0,     0,     5,     6,     7,     8,
       9,    69,     0,    70,     2,     3,     0,     0,    86,    71,
       1,    17,    18,    39,    20,    21,     6,     7,     8,     9,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
      17,    18,    39,    20,    21,     6,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    39,    20,    21,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
       0,    70,    55,    56,    57,    58,    59,    71,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    72,    70,
      55,    56,    57,    58,    59,    71,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,   110,    70,    55,    56,
      57,    58,    59,    71,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,   112,    70,    55,    56,    57,    58,
      59,    71,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,     0,    70,   120,     0,     0,     0,     0,    71,
      55,    56,    57,    58,    59,     0,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,     0,    70,    55,    56,
      57,    58,    59,    71,    61,    62,    63,    64,    65,    66,
       0,     0,     0,    69,     0,    70,    55,    56,    57,    58,
      59,    71,     0,     0,    63,    64,    65,    66,     0,     0,
       0,    69,     0,    70,     0,     0,     0,     0,     0,    71
  };

  const short
  parser::yycheck_[] =
  {
       1,     2,     3,   110,    23,     8,   111,    45,    47,    28,
      45,    18,    13,    29,    30,    31,    32,    20,     3,     4,
       5,     6,     7,    18,    18,    20,    45,    18,   135,    45,
     137,   136,    75,    18,    18,    20,   143,    20,     0,    22,
      20,    26,    18,    20,    20,    46,    47,    25,    49,    22,
      26,    19,    45,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     109,   114,   111,    45,    45,     3,     4,     5,     6,     7,
       7,     9,    10,    11,    12,    13,    14,    15,   131,    24,
      18,    18,    20,    20,    25,   138,    19,   136,    26,    26,
       4,    21,    24,    24,    19,    22,    25,    45,    21,    18,
     111,    35,    24,    17,    18,    20,    19,   118,    22,    25,
     121,    23,   109,    69,    28,    29,    30,    31,    32,    33,
      34,     4,    36,    37,    38,   136,    40,    41,    -1,    43,
      44,    45,    46,    47,    17,    18,    43,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      -1,    34,     4,    36,    37,    38,    -1,    40,    41,    -1,
      43,    44,    45,    46,    47,    17,    18,    -1,     5,     6,
       7,     4,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    18,    -1,    20,    17,    18,    -1,    -1,    21,    26,
       4,    43,    44,    45,    46,    47,    29,    30,    31,    32,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      -1,    20,     3,     4,     5,     6,     7,    26,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
       3,     4,     5,     6,     7,    26,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,     3,     4,
       5,     6,     7,    26,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,     3,     4,     5,     6,
       7,    26,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,    20,    21,    -1,    -1,    -1,    -1,    26,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,    20,     3,     4,
       5,     6,     7,    26,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    18,    -1,    20,     3,     4,     5,     6,
       7,    26,    -1,    -1,    11,    12,    13,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26
  };

  const signed char
  parser::yystos_[] =
  {
       0,     4,    17,    18,    22,    28,    29,    30,    31,    32,
      33,    34,    36,    37,    38,    40,    41,    43,    44,    45,
      46,    47,    51,    52,    53,    54,    57,    60,    61,    63,
      64,    65,    66,    67,    69,    70,    71,    72,    73,    45,
      73,    73,    73,    62,    45,    45,    18,    18,    73,    18,
      18,    18,     0,    53,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    18,
      20,    26,    19,    23,    63,    25,    22,    73,    64,    68,
      73,    73,    45,    45,    58,    59,    21,    73,    74,    75,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    73,    45,    45,    60,    55,
      19,    24,    19,    19,    25,    19,    24,    21,    24,    19,
      21,     8,    20,    23,    45,    56,    57,    64,    61,    68,
      60,    25,    45,    73,    73,    35,    24,    60,    25,    61,
      68,    61,    60,    19,    61
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    50,    51,    52,    52,    53,    53,    53,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    64,    64,    65,
      66,    66,    67,    68,    68,    68,    69,    70,    71,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     5,     0,
       2,     1,     1,     7,     0,     1,     3,     5,     1,     1,
       1,     1,     1,     3,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     3,
       5,     7,     9,     0,     1,     1,     2,     4,     4,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     4,     3,     4,     4,     0,     1,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "SUBOP",
  "MULTOP", "DIVOP", "POW", "ASS", "EQL", "NE", "LT", "GT", "LTE", "GTE",
  "AND", "OR", "NOT", "LP", "RP", "LS", "RS", "LL", "RL", "COMMA", "COLON",
  "DOT", "VAR", "VOL", "INT_T", "FLOAT_T", "BOOL_T", "VOID_T", "CLASS",
  "IF", "ELSE", "FOR", "RET", "BREAK", "CONT", "PRINT", "READ", "LEN",
  "TRUE", "FALSE", "ID", "INT", "FLOAT", "STR", "UNARY_MINUS", "$accept",
  "root", "program", "program_element", "class_declaration", "class_body",
  "class_member", "function_definition", "parameter_list", "parameters",
  "type", "block", "statements", "statement", "variable_declaration",
  "assignment_statement", "if_statement", "for_statement",
  "expression_opt", "return_statement", "print_statement",
  "read_statement", "break_statement", "expression", "argument_list",
  "arguments", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    56,    56,    60,    64,    71,    72,    73,    78,    86,
      87,    94,    95,   100,   110,   111,   115,   121,   131,   132,
     133,   134,   135,   136,   145,   149,   150,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   170,   175,   184,
     192,   197,   206,   216,   217,   218,   222,   229,   236,   242,
     247,   248,   249,   250,   251,   252,   254,   255,   256,   257,
     258,   259,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   271,   276,   281,   287,   295,   296,   300,   304
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1847 "parser.tab.cc"

#line 310 "parser.yy"

