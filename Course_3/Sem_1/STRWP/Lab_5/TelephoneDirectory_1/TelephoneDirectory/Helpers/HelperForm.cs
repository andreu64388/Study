using System;
using System.Linq.Expressions;
using Microsoft.AspNetCore.Html;
using Microsoft.AspNetCore.Mvc.Rendering;

namespace TelephoneDirectory.Helpers;

public static class DictionaryHtmlHelpers
{
    public static IHtmlContent DictionaryInputFor<TModel>(
        this IHtmlHelper<TModel> htmlHelper,
        string label,
        string name,
        string placeholder)
    {
        var div = new TagBuilder("div");
        div.AddCssClass("form-group");

        var labelTag = new TagBuilder("label");
        labelTag.InnerHtml.Append(label);
        labelTag.AddCssClass("control-label");

        var inputTag = new TagBuilder("input");
        inputTag.Attributes.Add("type", "text");
        inputTag.Attributes.Add("name", name);
        inputTag.Attributes.Add("placeholder", placeholder);
        inputTag.AddCssClass("form-control");

        div.InnerHtml.AppendHtml(labelTag);
        div.InnerHtml.AppendHtml(inputTag);

        return div;
    }

    public static IHtmlContent DictionaryInputUpdateFor<TModel, TResult>(
        this IHtmlHelper<TModel> htmlHelper,
        Expression<Func<TModel, TResult>> expression,
        string label,
        string placeholder)
    {
        var div = new TagBuilder("div");
        div.AddCssClass("form-group");

        var labelTag = htmlHelper.LabelFor(expression, label, new { @class = "control-label" });

        var inputTag = htmlHelper.TextBoxFor(expression, new { @class = "form-control", placeholder = placeholder });

        div.InnerHtml.AppendHtml(labelTag);
        div.InnerHtml.AppendHtml(inputTag);

        return div;
    }
    public static IHtmlContent DictionaryInputHiddenFor<TModel, TResult>(
        this IHtmlHelper<TModel> htmlHelper,
        Expression<Func<TModel, TResult>> expression)
    {
        var inputTag = htmlHelper.HiddenFor(expression);

        return inputTag;
    }
}

