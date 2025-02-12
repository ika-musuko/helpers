import { van, define } from "../van.js";
const {
  div,
} = van.tags;

{
  const styles = new CSSStyleSheet();
  styles.replaceSync(`
  `);

  define("", ({ $this, attr, mount }) => {
    $this.shadowRoot.adoptedStyleSheets = [styles];

    const props = {
      prop: attr("", "default value"),
    };

    mount(() => {
    });

    return div();
  });
}
