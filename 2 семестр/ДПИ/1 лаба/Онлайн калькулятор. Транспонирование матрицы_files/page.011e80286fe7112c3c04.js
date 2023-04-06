﻿(()=>{"use strict";var __webpack_modules__={396445:(e,t,o)=>{o.d(t,{default:()=>_});const _=(0,o(379333).makeIcon)("Icon56ErrorOutline","error_outline_56","0 0 56 56",'<symbol viewBox="0 0 56 56" xmlns="http://www.w3.org/2000/svg" id="error_outline_56"><g fill="none" fill-rule="evenodd"><path d="M0 0h56v56H0z" /><path d="M28 4c13.255 0 24 10.745 24 24S41.255 52 28 52 4 41.255 4 28 14.745 4 28 4Zm0 3C16.402 7 7 16.402 7 28s9.402 21 21 21 21-9.402 21-21S39.598 7 28 7Zm0 27a2 2 0 1 1 0 4 2 2 0 0 1 0-4Zm0-17.5a1.5 1.5 0 0 1 1.5 1.5v11l-.007.144A1.5 1.5 0 0 1 26.5 29V18l.007-.144A1.5 1.5 0 0 1 28 16.5Z" fill="currentColor" fill-rule="nonzero" /></g></symbol>',56,56,!1,void 0)},429449:(e,t,o)=>{function _(){return{icon:'<svg width="20" height="20" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg"><g id="user_outline_20__Icons" stroke="none" stroke-width="1" fill="none" fill-rule="evenodd"><g id="user_outline_20__Icons-20/user_outline_20"><g id="user_outline_20__user_outline_20"><path opacity=".1" d="M0 0h20v20H0z"/><path d="M12.5 5a2.5 2.5 0 1 0-5 0 2.5 2.5 0 0 0 5 0ZM14 5a4 4 0 1 1-8 0 4 4 0 0 1 8 0ZM4 15.5c0 .72.36 1 1 1h10c.64 0 1-.28 1-1 0-2.33-2.57-3.5-6-3.5s-6 1.17-6 3.5Zm-1.5 0c0-3.48 3.33-5 7.5-5s7.5 1.52 7.5 5c0 1.63-1.1 2.5-2.5 2.5H5c-1.4 0-2.5-.87-2.5-2.5Z" id="user_outline_20__Icon-Color" fill="currentColor" fill-rule="nonzero"/></g></g></g></svg>',name:"user_outline_20"}}o.d(t,{getIcon20UserOutline:()=>_})},80842:(e,t,o)=>{o.d(t,{GROUPS_ADMIN_LEVEL_USER:()=>_,GROUPS_ADMIN_LEVEL_ADMINISTRATOR:()=>a,USER_META_FIELD_IS_DONUT_PAID_MEMBER:()=>r,GROUPS_CLASS_EVENT:()=>i});var _=0,a=3,r="is_donut_paid_member",i=2},573734:(e,t,o)=>{o.d(t,{default:()=>m});o(382526),o(141817),o(66992),o(294986),o(241539),o(324603),o(339714),o(804723),o(115306),o(323123),o(333948),o(560285);var _=o(315544),a=o(726271),r=o(786067),i=o(40906),n=o(695724),d=o(49535),l=o(850167),s=o(650588),p=o(635676),u=o(803834),c=o(124041),w={init:function(e,t){if(!(e=(0,_.ge)(e)))return null;var o=(0,_.data)(e,"composer");if(o)return o;o={input:e,inited:!1,options:t},(0,_.data)(e,"composer",o),o.wddWrap=(0,_.ce)("div",{className:"composer_wdd clear_fix "+(t.wddClass||""),id:e.id+"_composer_wdd",innerHTML:'<input type="hidden" id="'+e.id+'_composer_wdd_term"/>'},{width:t.width||(0,_.getSize)(e)[0]}),t.appendTo&&(0,n.isFunction)(t.appendTo)?t.appendTo(o.wddWrap):(0,_.domInsertBefore)(o.wddWrap,e.nextSibling),o.wddInput=o.wddWrap.firstChild,o.wdd=WideDropdown.initSelect(o.wddWrap,(0,n.extend)({text:o.wddInput,input:e,noResult:t.lang.noResult||"",introText:t.lang.introText||"",toup:t.toup,wddOpts:t.wddOpts,searchKeys:t.searchKeys,width:"auto",onItemSelect:w.onItemSelect.bind(w).pbind(o),renderLimit:50},t.wddOpts||{url:"hints.php",params:{act:"a_json_friends",from:"composer"}})),e.dd=o.wddWrap.id,w.initEvents(o),t.media&&(o.addMedia=new window.MediaSelector(t.media.lnk,t.media.preview,t.media.types,t.media.options,t.media.gearEl,t.media.actionsEl)),(0,_.setStyle)(o.wddWrap,"width",""),o.inited=!0,w.updateAutoComplete(o),o.edit=t.edit,o.isReply=t.isReply,w.updateArticleConvertSuggest(o);var a=cur.onMediaChanged;return cur.onMediaChanged=function(){w.updateArticleConvertSuggest(o),a&&a()},o},initEvents:function(e){(0,d.addEvent)(e.input,"keyup keydown keypress",w.onKeyEvent.pbind(e)),(0,d.addEvent)(e.input,"click mousedown mouseup focus blur paste",w.onMouseEvent.pbind(e))},destroy:function(e){WideDropdown.deinit(e.wddWrap),(0,_.cleanElems)(e.input,e.wddWrap),(0,_.re)(e.wddWrap),e.inited=!1,e.addMedia&&e.addMedia.destroy(),(0,_.data)(e.input,"composer",null),(0,_.re)(e.articleConvertEl),e.articleConvertEl=!1},onKeyEvent:function(e,t){var o=!t.shiftKey&&(0,n.inArray)(t.keyCode,[d.KEY.UP,d.KEY.DOWN,d.KEY.RETURN]),r=e.wdd&&o;if("keypress"==t.type||"keydown"==t.type){if(t.keyCode==d.KEY.RETURN||10==t.keyCode){if(e.select&&e.select.isVisible())return(0,d.triggerEvent)(document,t.type,t),(0,d.cancelEvent)(t);if(t.ctrlKey&&(0,n.isFunction)(e.options.onSubmit))return!0}if(t.keyCode==d.KEY.TAB){var i=e.input,l=window.Emoji?Emoji.editableVal(i):"",s=w.getCursorPosition(i),p=(l.substr(0,s)+String.fromCodePoint(1)+l.substr(s)).match(/^[\s\S]*(@|\*)[\S]+\s*\([\s\S]*?\001[\s\S]*?\)\s*/);if(p){var u=p[0].length-1;return(0,_.elfocus)(e.input,u,u),(0,d.cancelEvent)(t)}}var c=0;for(var m in e.wdd.shown)c+=1;if(r&&(0,_.isVisible)(e.wdd.listWrap)&&c)return t.type==(a.browser.opera&&!a.browser.chrome?"keypress":"keydown")&&WideDropdown._textEvent(t),(0,d.cancelEvent)(t)}if("keyup"==t.type&&!r){if(65==t.keyCode&&t.ctrlKey)return;e.wdd&&(0,n.inArray)(t.keyCode,[d.KEY.SPACE,d.KEY.HOME,190,191,78,55,49])&&w.hideSelectList(e)}"keyup"!=t.type||r&&t.keyCode!=d.KEY.RETURN||w.updateAutoComplete(e,t),w.updateArticleConvertSuggest(e)},isArticleConvertSuggestAvailable:function(e){if(e.edit||e.isReply)return!1;var t=!!cur.wallAddMedia&&cur.wallAddMedia.types,o=!1;if(t)for(var _=0;_<t.length;_++)if("article"==t[_][0]){o=!0;break}if(!o||!(0,s.isArticleEditorAvailable)())return!1;var a=!0;return(0,n.each)(cur.wallAddMedia.getMedias()||[],(function(e,t){if(!(0,n.inArray)(t[0],["photo","video","postpone","mark_as_ads"]))return a=!1,!1})),!!a&&!!(cur.options.articleConvertThreshold>0&&e.curValue.length>=cur.options.articleConvertThreshold)},updateArticleConvertSuggest:function(e){if(w.isArticleConvertSuggestAvailable(e)){if(!e.articleConvertEl){var t=(0,_.gpeByClass)("post_field_wrap",e.input),o=(0,_.geByClass1)("post_actions_btns",t);e.articleConvertEl=c.FlatButton.render({children:(0,r.getLang)("profile_convert_to_article_short"),appearance:c.FlatButtonAppearance.ACCENT_OUTLINE,size:c.FlatButtonSize.M,round:!0,className:"article_post_convert"}),o?t.insertBefore(e.articleConvertEl,o):t.appendChild(e.articleConvertEl),(0,d.removeEvent)(e.articleConvertEl),(0,d.addEvent)(e.articleConvertEl,"click",(function(){cur.postComposer=e;var t=[];(0,n.each)(cur.wallAddMedia.getMedias()||[],(function(e,o){(0,n.inArray)(o[0],["photo","video"])&&t.push(o[0]+"_"+o[1])})),(0,l.openArticleEditor)(cur.oid,0,{text:e.curValue,medias:t})}))}(0,_.show)(e.articleConvertEl)}else(0,_.re)(e.articleConvertEl),delete e.articleConvertEl},onMouseEvent:function(e,t){"blur"!=t.type?("focus"!=t.type&&"click"!=t.type||w.updateAutoComplete(e,t),"paste"==t.type&&setTimeout(w.updateAutoComplete.pbind(e,t),0)):w.hideSelectList(e)},updateAutoComplete:function(e,t){var o=e.input,a=(e.options&&e.options.getValue||window.Emoji&&Emoji.editableVal||_.val)(o),r=Math.max(a.lastIndexOf("@"),a.lastIndexOf("*")),i=!1;if(r>-1){var n=w.getCursorPosition(o),d=a.substr(0,n),l=d.match(/(^|[\s.,:\'\"«»;>\)\(]|\#[\w_\.\u0400-\u04FF]+)[@\*]([^,@\*\(\)\?\!\s\n\r \u00A0]*)$/);r=Math.max(d.lastIndexOf("@"),d.lastIndexOf("*")),l&&"."!==l[2].substr(-1)&&(i=l[2])}!1===i&&delete e.ignoredTerm,void 0!==e.ignoredTerm&&i==e.ignoredTerm&&(i=!1),e.curValue=a,e.curTerm=i,e.curPos=r,(0,_.val)(e.wddInput,i),w.toggleSelectList(e),!t||"keyup"!=t.type&&"paste"!=t.type||(e.options.onValueChange&&e.options.onValueChange(a,"keyup"!=t.type),e.addMedia&&e.addMedia.checkMessageURLs(a,"keyup"!=t.type),e.options.checkLen&&e.options.checkLen(a))},toggleSelectList:function(e){var t=e.curTerm;!1===t?w.hideSelectList(e):w.showSelectList(e,t)},hideSelectList:function(e){e.wddInput.focused=!1,WideDropdown._hideList(e.wdd);var t=e.options||{};t.onHide&&t.onHide()},showSelectList:function(e,t){function o(o){e.wddInput.focused=!0,WideDropdown.items(e.wdd.id,o||[]),WideDropdown._updateList(e.wdd,!1,t);var _=e.options||{};_.onShow&&_.onShow()}"function"==typeof cur.wallMentions&&(cur.wallMentions=cur.wallMentions()),cur.wallMentions&&"function"==typeof cur.wallMentions.then?cur.wallMentions.then((function(e){o(e)})):o(cur.wallMentions)},onItemSelect:function(e,t){if(!t)return!1;var o=t[2].replace("@",""),a=t[8]||t[1],r=e.curValue.substr(0,e.curPos),i=e.curValue.substr(e.curPos),d=!!r.match(/\#[\w_\.\u0400-\u04FF]+$/i);document.activeElement.classList.contains("_im_text")&&(/^(?:id|club)\d{1,}$/.test(o)||(d=!0));var l=e.options.poster,s=window.Emoji&&void 0!==e.input.emojiId||l;s||l?i=(0,n.clean)(i):a=(0,n.replaceEntities)(a),cur.selNum=(cur.selNum||0)+1;var p=new RegExp("^(@|\\*)"+(0,n.escapeRE)(e.curTerm)+"(?:\\s+\\((?:(.*?)\\))?\\s*)?","");return i=i.replace(p,(function(e,t,_){var r=t+o+" ";return d?r+=s||l?'<span id="tmp_sel_'+cur.selNum+'"></span>':"":(r+=(s||l?'<span id="tmp_sel_'+cur.selNum+'">':"")+"(",r+=a.replace(/[\(\)\]\[]/g,""),r+=")"+(s||l?"</span>":"")+" "),r})),d||!r||r.match(/[\.\(\)\?\!\s\n\r\'\"«» \u00A0]$/)||(i=" "+i),w.hideSelectList(e),s||l?(Emoji.val(e.input,(0,n.clean)(r)+i),Emoji.focus(e.input),Emoji.editableFocus(e.input,(0,_.ge)("tmp_sel_"+cur.selNum),!0),l&&l.checkText()):((0,_.val)(e.input,r+i),(0,_.elfocus)(e.input)),(0,n.isFunction)(e.options.onItemSelect)&&e.options.onItemSelect(t),!1},getCursorPosition:function(e){if(void 0!==e.selectionStart)return e.selectionStart;if(void 0!==window.getSelection){var t=window.getSelection();if(!t||!t.rangeCount)return 0;var o=t.getRangeAt(0),a=o.cloneRange(),r=(0,_.ce)("div");return a.selectNodeContents(e),a.setEnd(o.startContainer,o.startOffset),r.appendChild(a.cloneContents()),(window.Emoji?Emoji.editableVal:_.val)(r).replace(/\n$/,"").length}return 0},getSendParams:function(e,t,o){var a=e.addMedia||{},d=a.chosenMedia||{},l=a&&a.getMedias?a.getMedias():[],s=a.shareData||{},c=e&&e.options.media&&e.options.media.options.limit||0,w=e.input,m=cur.posterWpe&&cur.posterWpeSendParams?cur.posterWpeSendParams.text:(0,n.trim)(window.Emoji?Emoji.editableVal(w):(0,_.val)(w)),b={message:m},f=0,g=(0,_.hasClass)((0,_.gpeByClass)("post",w),"suggest");(0,i.isArray)(d)&&d.length&&l.push((0,n.clone)(d)),(0,_.setStyle)(bodyNode,{cursor:"default"});var h=(0,_.ge)("wpe_cont"),v=(0,_.geByClass1)("wpe_error",h);function E(e){v||(v=(0,_.se)('<div class="wpe_error error"><div>'),h.insertBefore(v,(0,_.domFC)(h))),v.innerHTML=e.length>60?'<div class="msg_text">'+e+"</div>":e,(0,_.isVisible)(v)||((0,p.slideDown)(v,100),(0,u.scrollToY)((0,_.getXY)(v)[1]-15),(0,p.animate)((0,_.ge)("box_layer_wrap"),{scrollTop:0}))}if(v&&(0,_.hide)(v),l.length&&(0,n.each)(l,(function(e,d){var p;if((0,i.isArray)(d)&&d.length){var u=this[0],w=this[1];if(f>=c&&"postpone"!=u)return!1;switch(u){case"poll":var h=a.pollData(o);if(!h)return b.delayed=!0,!1;(0,n.intval)(w)&&(b.poll_id=(0,n.intval)(w)),w=h.question,delete h.question,b=(0,n.extend)(b,h);break;case"copyright":var v=a.copyrightData();if(v)return void(b=(0,n.extend)(b,v));break;case"share":if(s.failed||!s.title&&(!s.images||!s.images.length)&&!s.photo_url&&!s.video)return cur.shareLastParseSubmitted&&Date.now()-cur.shareLastParseSubmitted<2e3?(b.delayed=!0,!1):void 0;if((cur.options.share||{}).button_exclusive&&s.button_text&&s.button_action){var C;l.length>1&&(C=(0,r.getLang)("global_share_too_many_attachments")),b.message.split("\n").length-1>(cur.options.share||{}).button_exclusive_max_message_newlines&&(C=(0,r.getLang)("global_share_too_many_newlines")),b.message.length>(cur.options.share||{}).button_exclusive_max_message_len&&(C=(0,r.getLang)("global_share_too_long_message"));var M=(0,n.extractUrls)(" "+b.message+" "),y=(0,n.extractUrls)(" "+s.url+" ")[0];if(y&&M.length){"/"===y.query&&(y.query=""),"www."===y.domain.substr(0,4)&&(y.domain=y.domain.substr(4));for(var P=0;P<M.length;++P){var k=M[P];if("/"===k.query&&(k.query=""),"www."===k.domain.substr(0,4)&&(k.domain=k.domain.substr(4)),y.domain!=k.domain||y.query!=k.query){C=(0,r.getLang)("global_share_too_many_links");break}}}if(C)return E(C),b.delayed=!0,!1}if(!s.title)return E((0,r.getLang)("global_share_title_required")),b.delayed=!0,!1;if(!s.url)return E((0,r.getLang)("global_share_url_required")),b.delayed=!0,!1;if(s.url=new URL(s.url).href,s.video?(w=s.video_owner_id+"_"+s.video_id,b.snippet_video=1):w=s.prometheus?s.media:s.user_id&&s.photo_id&&!s.noPhoto?s.user_id+"_"+s.photo_id:"",s.share_upload_failed&&!w)return s.share_upload_failed=0,b.delayed=!0,!1;if(s.images&&s.images.length&&!(0,i.isArray)(s.images[cur.shareShowImg])&&!o&&!w&&!s.noPhoto&&!s.video)return a.uploadShare(t),b.delayed=!0,!1;if((cur.options.share||{}).require_image&&!w)return E((0,r.getLang)("global_share_image_required")),b.delayed=!0,!1;s.initialPattern&&(0,n.trim)(m)==s.initialPattern&&(b.message=""),s.is_vk_mini_app&&(b.is_vk_mini_app=!0,b.is_photo_edit=s.isPhotoEdit,b.image_offset=cur.shareShowImg),(0,n.extend)(b,{url:s.url,module:cur.module,mode:s.mode,title:(0,n.replaceEntities)(s.title),description:(0,n.replaceEntities)(s.description),button_text:(0,n.replaceEntities)(s.button_text),button_action:s.button_action,extra:s.extra,extra_data:s.extraData,photo_url:s.video?"":(0,n.replaceEntities)(s.photo_url),placeholder_inserted:s.placeholder_inserted,open_graph_data:(s.openGraph||{}).data,open_graph_hash:(s.openGraph||{}).hash});break;case"page":s.initialPattern&&(0,n.trim)(m)==s.initialPattern&&(b.message="");break;case"postpone":return b.postpone=(0,_.val)("postpone_date"+a.lnkId),void(cur.postponedLastDate=b.postpone);case"donut_duration":return;case"mark_as_ads":return void(b.mark_as_ads=1);case"pretty_cards":if(!a.prettyCardGallery)return;if(a.prettyCardGallery.needSendData())return a.prettyCardGallery.saveCards(t,(function(e){E(e)})),b.delayed=!0,!1;w=a.prettyCardGallery.getSendData().attachVal;break;case"donut_link":b["attach"+(f+1)+"_owner_id"]=null==(p=this[5])?void 0:p.owner_id}this[3]&&(0,n.trim)(m)==this[3]&&(b.message=""),g&&this[4]&&(w+="_"+this[4]),b["attach"+(f+1)+"_type"]=u,b["attach"+(f+1)]=w,f++}})),!a.multi&&(b.postpone||(a.postponeDate&&a.postponeIsTooltip||a.postponePreview)&&(b.postpone=(0,_.val)("postpone_date"+a.lnkId),cur.postponedLastDate=b.postpone),!b.copyright&&a.copyrightData)){var C=a.copyrightData();C&&(b=(0,n.extend)(b,C))}return a.multi||b.mark_as_ads||!a.markAsAds||(b.mark_as_ads=1),b},reset:function(e){var t=e.input,o=(0,_.val)(t),a=e.addMedia,r={value:o};return window.Emoji?Emoji.val(t,""):t.innerHTML="",a&&(r.urlsCancelled=(0,n.clone)(a.urlsCancelled),a.unchooseMedia(),a.urlsCancelled=[]),(0,_.re)(e.articleConvertEl),r},restore:function(e,t){var o=e.input,a=w.reset(e);return(0,_.val)(o,t.value||""),a}};const m=w},621126:(__unused_webpack___webpack_module__,__webpack_exports__,__webpack_require__)=>{__webpack_require__.d(__webpack_exports__,{default:()=>__WEBPACK_DEFAULT_EXPORT__});var core_js_modules_es_array_iterator__WEBPACK_IMPORTED_MODULE_0__=__webpack_require__(66992),core_js_modules_es_object_to_string__WEBPACK_IMPORTED_MODULE_1__=__webpack_require__(241539),core_js_modules_es_string_replace__WEBPACK_IMPORTED_MODULE_2__=__webpack_require__(115306),core_js_modules_es_typed_array_uint8_array__WEBPACK_IMPORTED_MODULE_3__=__webpack_require__(682472),core_js_modules_es_typed_array_includes__WEBPACK_IMPORTED_MODULE_4__=__webpack_require__(844731),core_js_modules_es_typed_array_to_locale_string__WEBPACK_IMPORTED_MODULE_5__=__webpack_require__(812974),core_js_modules_es_typed_array_to_string__WEBPACK_IMPORTED_MODULE_6__=__webpack_require__(915016),_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__=__webpack_require__(315544),_shared_lib_browser__WEBPACK_IMPORTED_MODULE_8__=__webpack_require__(726271),_web_lib_lang__WEBPACK_IMPORTED_MODULE_9__=__webpack_require__(786067),_web_lib_dom_events__WEBPACK_IMPORTED_MODULE_10__=__webpack_require__(49535),_web_lib_message_box__WEBPACK_IMPORTED_MODULE_11__=__webpack_require__(146143),_web_lib_ui__WEBPACK_IMPORTED_MODULE_12__=__webpack_require__(386409),_web_lib_ui_util__WEBPACK_IMPORTED_MODULE_13__=__webpack_require__(159121),_web_lib_utils_common__WEBPACK_IMPORTED_MODULE_14__=__webpack_require__(695724),_shared_lib_convert__WEBPACK_IMPORTED_MODULE_15__=__webpack_require__(668040),WallUpload={_videoUploadIndex:null,photoUploaded:function(e,t){var o=void 0!==e.ind?e.ind:e,_=(e.fileName?e.fileName:e).replace(/[&<>"']/g,""),a=e.fileName?o+"_"+e.fileName:e,r=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("upload"+a+"_progress_wrap");r&&(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.hide)((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.geByClass1)("progress_x",r)),ajax.post("al_photos.php",(0,_web_lib_utils_common__WEBPACK_IMPORTED_MODULE_14__.extend)({act:"choose_uploaded"},t),{onDone:function(e,t){WallUpload.addMedia().chooseMedia("photo",e,(0,_web_lib_utils_common__WEBPACK_IMPORTED_MODULE_14__.extend)(t,{upload_ind:o+"_"+_}))},onFail:WallUpload.uploadFailed.pbind(e)})},uploadFailed:function(e,t){var o=void 0!==e.ind?e.ind:e,_=Upload.options[o],a=(e.fileName?e.fileName:e).replace(/[&<>"']/g,"");if("fileApi"==Upload.types[o]&&!_.wiki_editor){var r,i=e.fileName?o+"_"+e.fileName:e;cur.imMedia?((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.re)("upload"+i+"_progress_wrap"),r=cur.imMedia.lnkId,cur.addMedia[r].unchooseMedia()):cur.addMedia&&((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.re)("upload"+i+"_progress_wrap"),(r=(cur.attachMediaIndexes||{})[a])&&cur.addMedia[r].unchooseMedia()),1==_.filesTotalCount&&setTimeout((0,_web_lib_message_box__WEBPACK_IMPORTED_MODULE_11__.showFastBox)({title:(0,_web_lib_lang__WEBPACK_IMPORTED_MODULE_9__.getLang)("global_error")},(0,_web_lib_lang__WEBPACK_IMPORTED_MODULE_9__.getLang)("wall_add_photo_error")).hide,2e3)}(0,_web_lib_ui_util__WEBPACK_IMPORTED_MODULE_13__.topError)("Upload failed",{dt:-1,type:102,url:((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("file_uploader_form"+o)||{}).action}),Upload.embed(o)},show:function(){cur.uploadInited&&("feed"==cur.wallType?(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.removeClass)(cur.uploadWrap,"post_upload_min_wrap"):(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.show)(cur.uploadWrap))},hide:function(){cur.uploadInited&&("feed"==cur.wallType?(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.addClass)(cur.uploadWrap,"post_upload_min_wrap"):(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.hide)(cur.uploadWrap),(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.hide)("post_upload_dropbox"))},addMedia:function(){return cur.dropboxAddMedia||cur.wallAddMedia},attachEl:function(){return WallUpload.dropboxAttachEl||(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("submit_post_box")},attachToEl:function(e){e=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)(e);var t=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("post_upload_dropbox");if(WallUpload.dropboxAttachEl=e,!e||!t)return!1;e.insertBefore(t,(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.domFC)(e))},checkDragDrop:function(){var e=_shared_lib_browser__WEBPACK_IMPORTED_MODULE_8__.browser,t=(0,_web_lib_utils_common__WEBPACK_IMPORTED_MODULE_14__.floatval)(_shared_lib_browser__WEBPACK_IMPORTED_MODULE_8__.browser.version);return!!(e.msie&&t>=9||e.mozilla&&t>=3.5||e.chrome||e.safari)&&((window.XMLHttpRequest||window.XDomainRequest)&&(window.FormData||window.FileReader&&(window.XMLHttpRequest&&XMLHttpRequest.sendAsBinary||window.ArrayBuffer&&window.Uint8Array&&(window.MozBlobBuilder||window.WebKitBlobBuilder||window.BlobBuilder))))},initCallback:function(){cur.editingPost?WallUpload.init():Wall.showEditPost()},init:function(){cur.withUpload&&(cur.uploadAdded?WallUpload.show():(cur.uploadAdded=!0,window.Upload&&window.VideoInlineUpload?(WallUpload.initLoader(),Wall._videoUploadIndex=WallUpload.initVideoUploader()):window.stManager.add([window.jsc("web/upload.js"),"video_upload.js"],(function(){WallUpload.initLoader(),Wall._videoUploadIndex=WallUpload.initVideoUploader()}))))},initVideoUploader:function(){var e=cur.wallUploadVideoOpts;if(e){var t=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("post_field_upload_video"),o=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("post_upload_video_dropbox");e.options.from="post";var _=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("send_post"),a={onUploadAllCompleteDone:function(){(0,_web_lib_ui__WEBPACK_IMPORTED_MODULE_12__.disableButton)(_,!1)},onUploadStartDone:function(){(0,_web_lib_ui__WEBPACK_IMPORTED_MODULE_12__.disableButton)(_,!0)}};return window.VideoInlineUpload.getUploadModule(t,o,e,WallUpload.addMedia(),a)}},initLoader:function initLoader(){(0,_web_lib_dom_events__WEBPACK_IMPORTED_MODULE_10__.removeEvent)(bodyNode,"dragover dragenter");var data=cur.wallUploadOpts,field=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("post_field");if(WallUpload.checkDragDrop()){cur.uploadWrap=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ce)("div",{className:"post_upload_wrap fl_r",innerHTML:'<div id="post_field_upload" class="post_upload"></div>'}),(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.domInsertBefore)(cur.uploadWrap,field),cur.uploadVideoWrap=(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ce)("div",{className:"post_upload_video_wrap fl_r",innerHTML:'<div id="post_field_upload_video" class="post_upload_video"></div>'}),(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.domInsertBefore)(cur.uploadVideoWrap,field);var submitBox=WallUpload.attachEl();submitBox.insertBefore((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ce)("div",{id:"post_upload_dropbox",className:"post_upload_dropbox",innerHTML:'<div class="post_upload_dropbox_inner"><div class="post_upload_label drop_label">'+(data.opts.lang.wall_drop_media_here||"Drop files here")+'</div><div class="post_upload_label release_label">'+(data.opts.lang.wall_release_media_here||"Release button to attach files")+"</div></div>"}),submitBox.firstChild),cur.wallUploadInd=Upload.init("post_field_upload",data.url,data.params,{accept:"image/jpeg,image/png,image/gif",dragEl:bodyNode,dropbox:"post_upload_dropbox",file_input:null,file_name:"photo",file_size_limit:26214400,file_types_description:"Image files (*.jpg, *.jpeg, *.png, *.gif)",file_types:"*.jpg;*.JPG;*.jpeg;*.JPEG;*.png;*.PNG;*.gif;*.GIF",file_match:data.opts.ext_re,lang:data.opts.lang,multiple:1,multi_progress:1,max_files:10,chooseBox:1,clear:1,type:"photo",max_attempts:3,server:data.opts.server,error:data.opts.default_error,error_hash:data.opts.error_hash,label:data.opts.label,wiki_editor:0,onUploadStart:function(e,t){var o=void 0!==e.ind?e.ind:e,_=Upload.options[o];"form"==Upload.types[o]&&((0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.geByClass1)("file",(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.ge)("choose_photo_upload")).disabled=!0),"fileApi"==Upload.types[o]&&(cur.notStarted&&(cur.preventBoxHide||boxQueue.hideLast(),delete cur.notStarted),_.multi_progress&&this.onUploadProgress(e,0,0))},onUploadComplete:function onUploadComplete(info,res){var params;try{params=eval("("+res+")")}catch(e){params=(0,_shared_lib_convert__WEBPACK_IMPORTED_MODULE_15__.fromQueryString)(res)}params.photos?WallUpload.photoUploaded(info,params):Upload.onUploadError(info)},onUploadProgress:function(e,t,o){var _=void 0!==e.ind?e.ind:e;if("fileApi"==Upload.types[_]){var a=(cur.attachMediaIndexes||{})[_];if(void 0===a||a&&cur.addMedia[a].chosenMedia||cur.imMedia){var r={loaded:t,total:o};e.fileName&&(r.fileName=e.fileName.replace(/[&<>"']/g,"")),WallUpload.addMedia().showMediaProgress("photo",_,r)}}},onUploadError:WallUpload.uploadFailed,onCheckServerFailed:function(){delete cur.uploadInited,WallUpload.hide()},onUploadCompleteAll:function(e){"form"==Upload.types[e]&&Upload.embed(e)},onDragEnter:function(){cur.editingPost?(Wall.hidePosterFeatureTooltip(),WallUpload.init()):Wall.showEditPost()},onNoFilteredCallback:function(e){Wall._videoUploadIndex&&Upload.onFileApiSend(Wall._videoUploadIndex,e)}}),cur.uploadInited=!0,WallUpload.show(),cur.wallUploadFromDrag&&(1==cur.wallUploadFromDrag&&(0,_web_lib_dom__WEBPACK_IMPORTED_MODULE_7__.show)("post_upload_dropbox"),delete cur.wallUploadFromDrag)}}};const __WEBPACK_DEFAULT_EXPORT__=WallUpload},906523:(e,t,o)=>{function _(){return Boolean(window.nav&&window.nav.objLoc&&window.nav.objLoc.claim)}o.d(t,{isClaimContent:()=>_})},287503:(e,t,o)=>{o.d(t,{GroupAdminLevel:()=>_});var _={USER:0,MODERATOR:1,EDITOR:2,ADMINISTRATOR:3,HOST:4,EVENT_CREATOR:5,CREATOR:6,PSEUDO_LEVEL_ADVERTISER:100}},222519:(e,t,o)=>{o.d(t,{TOOLTIP_SUCCESS_EVENT:()=>a,TooltipEventService:()=>r});var _=o(340189),a="group_tooltip_success_event",r={onUploadAvatar:function(){window.dispatchEvent(new CustomEvent(a,{detail:_.OnboardingTooltipIds.Avatar}))},onUploadCover:function(){window.dispatchEvent(new CustomEvent(a,{detail:_.OnboardingTooltipIds.Cover}))},onAddPost:function(){window.dispatchEvent(new CustomEvent(a,{detail:_.OnboardingTooltipIds.Post}))},onAddMarketItem:function(){window.dispatchEvent(new CustomEvent(a,{detail:_.OnboardingTooltipIds.MarketItem}))},onAddServiceItem:function(){window.dispatchEvent(new CustomEvent(a,{detail:_.OnboardingTooltipIds.ServiceItem}))}}},340189:(e,t,o)=>{var _;o.d(t,{OnboardingTooltipIds:()=>_}),function(e){e.Avatar="business_groups_web:avatar",e.Cover="business_groups_web:cover",e.ActionButton="business_groups_web:action_button",e.MarketItem="business_groups_web:add_item",e.ServiceItem="business_groups_web:add_service",e.Post="business_groups_web:make_post"}(_||(_={}))},599647:(e,t,o)=>{var _=o(182804),a=o(786067),r=o(146143),i=o(786665),n=o(375617),d=o(621126),l=o(573734),s=o(982452),p=o(215614);window.Page=i.default,window.page=i.default,window.Wall=n.default,window.wall=n.default,window.WallUpload=d.default,window.Composer=l.default,window._postsSendTimer||(window._postsSendTimer=window.setTimeout(i.default.postsSend,1e4));try{window.stManager.done("page.js"),(0,_.tq)().setInteractiveHandler("Wall/fake_news_info",(function(e){var t=e.payload,o=t.event,_=t.dataAttrs;null==o||o.preventDefault();var a=_,r=a.title,i=a.text,n=a.more_button_text,d=a.more_button_url,l=a.ok_button_text;(0,p.showFakeInfoNotification)({title:r,text:i,more_button_text:n,more_button_url:d,ok_button_text:l}),window.ajax.post("al_page.php",{act:"track_fake_news_caption_clicked"})})),(0,_.tq)().setInteractiveHandler("Page/owner_new_photo",(function(e){try{var t=e.payload.dataAttrs.options,o=JSON.parse(t),_=o.ownerId;o.useNewForm?i.default.ownerAvatarUpload(_):i.default.ownerPhoto(_)}catch(e){(0,s.showErrorBox)((0,a.getLang)("global_error"))}})),(0,_.tq)().setInteractiveHandler("Page/owner_edit_photo",(function(e){try{var t=e.payload.dataAttrs.options,o=JSON.parse(t),_=o.ownerId,r=o.hash;o.useNewForm?i.default.ownerAvatarEdit(_,r):i.default.ownerCrop(_,r)}catch(e){(0,s.showErrorBox)((0,a.getLang)("global_error"))}})),(0,_.tq)().setInteractiveHandler("Page/owner_set_exist_photo",(function(e){try{var t=e.payload.dataAttrs.options,o=JSON.parse(t),_=o.photo;o.useNewForm?i.default.ownerAvatarSelect(_):(0,r.showBox)("al_page.php",{act:"owner_photo_edit",photo:_},{stat:["owner_photo.css",window.jsc("web/owner_photo.js"),"tagger.css",window.jsc("web/tagger.js")]})}catch(e){(0,s.showErrorBox)((0,a.getLang)("global_error"))}}))}catch(e){}},215614:(e,t,o)=>{o.d(t,{showFakeInfoNotification:()=>l});var _=o(570655),a=o(785893),r=o(481117),i=o(288420),n=o(396445),d=function(e){var t=e.title,o=e.text,r=e.more_button_text,d=e.more_button_url,l=e.ok_button_text,s=e.onClose;return(0,a.jsxs)("div",(0,_.__assign)({className:"FakeInfoWarning__box"},{children:[(0,a.jsx)("div",(0,_.__assign)({className:"FakeInfoWarning__imageContainer"},{children:(0,a.jsx)(n.default,{},void 0)}),void 0),(0,a.jsx)("div",(0,_.__assign)({className:"FakeInfoWarning__title"},{children:t}),void 0),(0,a.jsx)("div",(0,_.__assign)({className:"FakeInfoWarning__text"},{children:o}),void 0),!!d&&(0,a.jsx)("a",(0,_.__assign)({href:d,target:"_blank",rel:"noopener"},{children:r}),void 0),(0,a.jsx)("div",(0,_.__assign)({className:"FakeInfoWarning__buttonWrap"},{children:(0,a.jsx)(i.default,(0,_.__assign)({onClick:s,appearance:"primary"},{children:l}),void 0)}),void 0)]}),void 0)};function l(e){(0,r.showComponentInBox)((0,a.jsx)(d,(0,_.__assign)({},e,{onClose:function(){(0,r.destroyComponentInBox)(!0)}}),void 0),{containerClass:"FakeInfoWarning"})}},186699:(e,t,o)=>{o.d(t,{ReportReasonIds:()=>c,showReportForm:()=>m,afterCommentReportSubmit:()=>b});var _,a,r=o(785893),i=o(249511),n=o(787481),d=o(786067),l=o(196022),s=o(189798),p=o(448632),u=o(548838);(0,l.makeAuthAndApiGlobal)();var c,w=window.vk;function m(e,t,_,a,n){var d=(0,u.asyncComponent)((function(){return Promise.all([o.e(24509),o.e(98066),o.e(68592),o.e(29019)]).then(o.bind(o,71018))}),(function(e){return e.ReportForm})),l=(0,r.jsx)(d,{reportSource:e,reportSourceOwnerId:t,reportSourceId:_,onSubmit:a},void 0),s={onDestroy:n};(0,i.showComponentInBoxSuspense)(l,s)}function b(e,t,o){var _=function(e,t,o){switch(e){case"photo":return"#post"+t+"photo_"+o;case"video":return"#post"+t+"video_"+o+"mv";case"market":return"#post"+t+"market_"+o}}(e,t,o);if("photo"===e){var a=document.querySelector(_+" .dld");null!==a&&(a.outerHTML="")}var r=document.querySelector(_+" .reply_wrap");null!==r?(r.style.display="none",r.outerHTML+='<div class="dld">'+(0,d.getLang)("global_report_sent")+"</div>"):(0,n.debugLog)("Unable to hide report button for "+e+" comment")}(0,s.setLoginConfig)({onCaptcha:p.handleCaptcha,domain:null===(_=null==w?void 0:w.apiConfigDomains)||void 0===_?void 0:_.loginDomain}),(0,s.setApiConfig)({onCaptcha:p.handleCaptcha,domain:null===(a=null==w?void 0:w.apiConfigDomains)||void 0===a?void 0:a.apiDomain}),function(e){e[e.NotOriginalContent=28]="NotOriginalContent"}(c||(c={}))},175382:(e,t,o)=>{o.d(t,{floatingButtonCollapseAllRepliesHide:()=>r,floatingButtonCollapseAllRepliesShow:()=>i,loadRepliesLinkShow:()=>n,loadRepliesLinkIsVisible:()=>d,highlightUpdatedReply:()=>l,highlightUpdatedReplyContent:()=>s});var _=o(830104),a=o(315544),r=function(e){e instanceof HTMLElement&&e.classList.contains("replies_side")&&e.classList.add("replies_side_hidden")},i=function(e){e instanceof HTMLElement&&e.classList.contains("replies_side")&&e.classList.remove("replies_side_hidden")},n=function(e){e instanceof HTMLElement&&e.classList.contains("replies_next")&&e.classList.add("replies_next_shown")},d=function(e){return!!(e instanceof HTMLElement&&e.classList.contains("replies_next"))&&(e.classList.contains("replies_next_shown")||(0,a.isVisible)(e))},l=function(e){(0,_.triggerAnimationClass)(e,"reply_highlight_updated",3e3)},s=function(e){(0,_.triggerAnimationClass)(e,"reply_highlight_updated_content",3e3)}}},__webpack_module_cache__={},deferred,leafPrototypes,getProto,inProgress,loadStylesheet,installedCssChunks;function __webpack_require__(e){var t=__webpack_module_cache__[e];if(void 0!==t)return t.exports;var o=__webpack_module_cache__[e]={id:e,loaded:!1,exports:{}};return __webpack_modules__[e].call(o.exports,o,o.exports,__webpack_require__),o.loaded=!0,o.exports}__webpack_require__.m=__webpack_modules__,deferred=[],__webpack_require__.O=(e,t,o,_)=>{if(!t){var a=1/0;for(d=0;d<deferred.length;d++){for(var[t,o,_]=deferred[d],r=!0,i=0;i<t.length;i++)(!1&_||a>=_)&&Object.keys(__webpack_require__.O).every((e=>__webpack_require__.O[e](t[i])))?t.splice(i--,1):(r=!1,_<a&&(a=_));if(r){deferred.splice(d--,1);var n=o();void 0!==n&&(e=n)}}return e}_=_||0;for(var d=deferred.length;d>0&&deferred[d-1][2]>_;d--)deferred[d]=deferred[d-1];deferred[d]=[t,o,_]},__webpack_require__.n=e=>{var t=e&&e.__esModule?()=>e.default:()=>e;return __webpack_require__.d(t,{a:t}),t},getProto=Object.getPrototypeOf?e=>Object.getPrototypeOf(e):e=>e.__proto__,__webpack_require__.t=function(e,t){if(1&t&&(e=this(e)),8&t)return e;if("object"==typeof e&&e){if(4&t&&e.__esModule)return e;if(16&t&&"function"==typeof e.then)return e}var o=Object.create(null);__webpack_require__.r(o);var _={};leafPrototypes=leafPrototypes||[null,getProto({}),getProto([]),getProto(getProto)];for(var a=2&t&&e;"object"==typeof a&&!~leafPrototypes.indexOf(a);a=getProto(a))Object.getOwnPropertyNames(a).forEach((t=>_[t]=()=>e[t]));return _.default=()=>e,__webpack_require__.d(o,_),o},__webpack_require__.d=(e,t)=>{for(var o in t)__webpack_require__.o(t,o)&&!__webpack_require__.o(e,o)&&Object.defineProperty(e,o,{enumerable:!0,get:t[o]})},__webpack_require__.f={},__webpack_require__.e=e=>Promise.all(Object.keys(__webpack_require__.f).reduce(((t,o)=>(__webpack_require__.f[o](e,t),t)),[])),__webpack_require__.u=e=>9375===e?"voice_message_player.085a6af3cff0eb34a07f.js":28762===e?"speech.3645439881096efb84f2.js":57468===e?"SilentModeForms.484705a4b8caa25ca515.js":29019===e?"ReportForm.c334b68d784ac7aa520b.js":77806===e?"apps_attach_modal.6a86943848875bd5f6e2.js":55489===e?"lottie-light.19743fa6c7bec04c41d3.js":38288===e?"lottie.7d914fa3404556039ac3.js":void 0,__webpack_require__.miniCssF=e=>e+"."+{29019:"98fcb09429461c848423",57468:"cbe3f93743d8887c18a7",77806:"c23986869c7733c2cff9"}[e]+".css",__webpack_require__.g=function(){if("object"==typeof globalThis)return globalThis;try{return this||new Function("return this")()}catch(e){if("object"==typeof window)return window}}(),__webpack_require__.o=(e,t)=>Object.prototype.hasOwnProperty.call(e,t),inProgress={},__webpack_require__.l=(e,t,o,_)=>{if(inProgress[e])inProgress[e].push(t);else{var a,r;if(void 0!==o)for(var i=document.getElementsByTagName("script"),n=0;n<i.length;n++){var d=i[n];if(d.getAttribute("src")==e||d.getAttribute("data-webpack")=="vk:"+o){a=d;break}}a||(r=!0,(a=document.createElement("script")).charset="utf-8",a.timeout=120,__webpack_require__.nc&&a.setAttribute("nonce",__webpack_require__.nc),a.setAttribute("data-webpack","vk:"+o),a.src=e),inProgress[e]=[t];var l=(t,o)=>{a.onerror=a.onload=null,clearTimeout(s);var _=inProgress[e];if(delete inProgress[e],a.parentNode&&a.parentNode.removeChild(a),_&&_.forEach((e=>e(o))),t)return t(o)},s=setTimeout(l.bind(null,void 0,{type:"timeout",target:a}),12e4);a.onerror=l.bind(null,a.onerror),a.onload=l.bind(null,a.onload),r&&document.head.appendChild(a)}},__webpack_require__.r=e=>{"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},__webpack_require__.nmd=e=>(e.paths=[],e.children||(e.children=[]),e),__webpack_require__.p="/dist/",loadStylesheet=e=>new Promise(((t,o)=>{var _=__webpack_require__.miniCssF(e),a=__webpack_require__.p+_;if(((e,t)=>{for(var o=document.getElementsByTagName("link"),_=0;_<o.length;_++){var a=(i=o[_]).getAttribute("data-href")||i.getAttribute("href");if("stylesheet"===i.rel&&(a===e||a===t))return i}var r=document.getElementsByTagName("style");for(_=0;_<r.length;_++){var i;if((a=(i=r[_]).getAttribute("data-href"))===e||a===t)return i}})(_,a))return t();((e,t,o,_)=>{var a=document.createElement("link");a.rel="stylesheet",a.type="text/css",a.onerror=a.onload=r=>{if(a.onerror=a.onload=null,"load"===r.type)o();else{var i=r&&("load"===r.type?"missing":r.type),n=r&&r.target&&r.target.href||t,d=new Error("Loading CSS chunk "+e+" failed.\n("+n+")");d.code="CSS_CHUNK_LOAD_FAILED",d.type=i,d.request=n,a.parentNode.removeChild(a),_(d)}},a.href=t,document.head.appendChild(a)})(e,a,t,o)})),installedCssChunks={60339:0},__webpack_require__.f.miniCss=(e,t)=>{installedCssChunks[e]?t.push(installedCssChunks[e]):0!==installedCssChunks[e]&&{29019:1,57468:1,77806:1}[e]&&t.push(installedCssChunks[e]=loadStylesheet(e).then((()=>{installedCssChunks[e]=0}),(t=>{throw delete installedCssChunks[e],t})))},(()=>{var e={60339:0};__webpack_require__.f.j=(t,o)=>{var _=__webpack_require__.o(e,t)?e[t]:void 0;if(0!==_)if(_)o.push(_[2]);else{var a=new Promise(((o,a)=>_=e[t]=[o,a]));o.push(_[2]=a);var r=__webpack_require__.p+__webpack_require__.u(t),i=new Error;__webpack_require__.l(r,(o=>{if(__webpack_require__.o(e,t)&&(0!==(_=e[t])&&(e[t]=void 0),_)){var a=o&&("load"===o.type?"missing":o.type),r=o&&o.target&&o.target.src;i.message="Loading chunk "+t+" failed.\n("+a+": "+r+")",i.name="ChunkLoadError",i.type=a,i.request=r,_[1](i)}}),"chunk-"+t,t)}},__webpack_require__.O.j=t=>0===e[t];var t=(t,o)=>{var _,a,[r,i,n]=o,d=0;for(_ in i)__webpack_require__.o(i,_)&&(__webpack_require__.m[_]=i[_]);if(n)var l=n(__webpack_require__);for(t&&t(o);d<r.length;d++)a=r[d],__webpack_require__.o(e,a)&&e[a]&&e[a][0](),e[r[d]]=0;return __webpack_require__.O(l)},o=self.webpackChunkvk=self.webpackChunkvk||[];o.forEach(t.bind(null,0)),o.push=t.bind(null,o.push.bind(o))})();var __webpack_exports__=__webpack_require__.O(void 0,[76429,75514,24509,56990,98066,76400,40885,68592,4502,59302,85820,83063],(()=>__webpack_require__(599647)));__webpack_exports__=__webpack_require__.O(__webpack_exports__)})();