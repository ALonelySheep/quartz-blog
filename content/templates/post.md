---
title: "<% tp.file.title %>"
tags:
- all
<% tp.file.tags.map(b=>'- '+b.slice(1)).join("\n") %>
date: "<% tp.user.find_date(tp) %>"
---
