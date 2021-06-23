import App from './App.svelte';
import { entrypoints } from 'uxp';

var app = new App({
  target: document.body,
});

entrypoints.setup({
  plugin: {
    create(plugin: any) {
      console.log('Plugin created successfully!', plugin);
    },
    panels: {
      app: app,
    },
  },
});

// Hot Module Replacement (HMR) - Remove this snippet to remove HMR.
// Learn more: https://www.snowpack.dev/concepts/hot-module-replacement
if (import.meta.hot) {
  import.meta.hot.accept();
  import.meta.hot.dispose(() => {
    app.$destroy();
  });
}
